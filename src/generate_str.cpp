#include <string>

std::string GenerateString(long long target_size_mb, const std::string& sub_str) {
    std::string base_chunk = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    const long long target_size_bytes = target_size_mb * 1024 * 1024;
    const size_t chunk_len = base_chunk.length();
    const int repetitions = target_size_bytes / chunk_len;
    std::string generated_str;
    generated_str.reserve(target_size_bytes + 5 * sub_str.length()); 
    
    for (int i = 0; i < repetitions; ++i) {
        generated_str += base_chunk;
    }
    
    if (!generated_str.empty()) {
        size_t len = generated_str.length();
        generated_str.insert(0, sub_str);  
        generated_str.insert(len / 4 + sub_str.length(), sub_str); 
        generated_str.insert(len / 2 + 2 * sub_str.length(), sub_str);  
        generated_str.insert((3 * len / 4) + 3 * sub_str.length(), sub_str);  
        generated_str.insert(generated_str.length() - chunk_len * 2, sub_str);  
    }
    return generated_str;
}