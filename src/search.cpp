#include "thread_data.h"

#include <iostream>


void *search(void * arg) {
    ThreadData * data = static_cast<ThreadData *>(arg);
    size_t sub_len = data->sub_str->length();
    for (size_t i = data->start_seek; i <= data->end_seek; ++i) {
        int flag = 1;
        for (size_t j = 0; j < sub_len; ++j) {
            if ((*data->str)[i + j] != (*data->sub_str)[j]) {
                flag = 0;
                break;
           }
        }
        if (flag) {
            std::cout << "найден образ на позиции " << i << std::endl;
        }
    }
    delete data;
    return NULL;
}