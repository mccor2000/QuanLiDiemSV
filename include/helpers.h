#pragma once 
#include<string>


std::string Notify(std::string text){
    return "Thong bao : " + text;
}
std::string Warning(std::string text){
    return "Canh bao : " + text;
}
std::string Error(std::string text){
    return "Loi : " + text;
}
