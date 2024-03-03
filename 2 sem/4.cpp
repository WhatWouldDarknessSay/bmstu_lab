#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
class file_open_error{};
class file_read_error{};
class file_write_error{};
int count_unique(string str)
{
    unordered_set<char> s;
    for (int i = 0; i < str.size(); i++) {
        s.insert(str[i]);
    }
    return s.size();
}

int main(){
    try{
    FILE* in_file= fopen("4_input.txt", "r");
    FILE *out_file= fopen("4_output.txt", "w");
    if(!in_file or !out_file){throw file_open_error();}
    while (!feof(in_file)){
        string word = "";
        int ch;
        while(((ch = fgetc(in_file)) != EOF) && (ch != ' ')){
            word += ch;
        }
        if(word == ""){throw file_read_error();}
        cout << word.length() << " " << count_unique(word) << " " << (float)word.length() / (float)count_unique(word) << "\n";
        if((float)word.length() / (float)count_unique(word) <= 2){
            word += '\n';
            try{
                
                fputs(word.c_str(), out_file);
            } catch (...){
                throw file_write_error();
            }
        }
    }
    fclose(in_file);
    fclose(out_file);
    } catch(file_open_error){
        cerr << "Ошибка открытия файла";
    } catch(file_read_error){
        cerr << "Ошибка чтения файла";
    } catch(file_write_error){
        cerr << "Ошибка записи в файл";
    }
}