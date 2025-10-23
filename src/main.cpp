    #include <chrono>
    #include <cstddef>
    #include <cstdlib>
    #include <pthread.h>
    #include <iostream>
    #include <string>
    
    #include "thread_data.h"
    #include "search.h"
    #include "generate_str.h"
    #include "os.h"  

    int main(int argc, char * argv[]) {
        if (argc != 2) {
            std::cerr << "Использование: ./main <число потоков>" << std::endl;
            exit(-1);
        }
        std::string const sub_str = "test";
        std::string const str = GenerateString(100, sub_str);
        size_t num_threads = std::atoi(argv[1]);

        auto start_time = std::chrono::high_resolution_clock::now();

        OsThread threads[num_threads];
        size_t curr_start = 0;
        size_t step = (str.length() - sub_str.length() + 1) / num_threads;
        size_t ost = (str.length() - sub_str.length() + 1) % num_threads;

        for (size_t i = 0; i < num_threads; ++i) {
            int add;
            if (i < ost) {
                add = step + 1;
            } else {
                add = step;
            }
            ThreadData * data = new ThreadData;
            data->start_seek = curr_start;
            data->end_seek = curr_start + add - 1;
            data->id = i + 1;
            data->str = &str;  
            data->sub_str = &sub_str;
            CreateThread(&threads[i], search, data);
            curr_start += add;
        } 
        for (size_t i = 0; i < num_threads; ++i) {  
            JoinThread(threads[i]);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
        std::cout << "Количество потоков: " << num_threads << std::endl;
        std::cout << "Время выполнения: " << duration.count() << " мс" << std::endl;
        
        return 0;
    }
