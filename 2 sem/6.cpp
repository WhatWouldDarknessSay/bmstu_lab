#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include  <bits/stdc++.h>
using namespace std;

class file_open_error{};
class file_read_error{};
class file_write_error{};
class push_error{};

struct Node {
    string name;
    string group;
    Node* next;
    Node* prev;
    Node(string _name, string _group) : name(_name), group(_group), next(nullptr), prev(nullptr){}
};

struct Doublelist {
    Node* first;
    Node* last;
    bool is_empty() {
        return first == nullptr;
    }
    Doublelist() : first(nullptr), last(nullptr) {}

    void push_back(string _name, string _group) {
        Node* p = new Node(_name, _group);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->prev = last;
        last->next = p;
        last = p;
    }
    void push_here(string _name, string _group, Node* p){
        Node* n = new Node(_name, _group);
        n->prev = p;
        n->next = p->next;
        p->next->prev = n;
        p->next = n;
    }
    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->name << " " << p->group;
            p = p->next;
        }
        cout << endl;
    }
};

int main(){
    try{
    FILE *out_file= fopen("6_output.txt", "w");
    FILE *out_file_bin= fopen("6_output.bin", "wb");

    Doublelist l;
    int n;
    string tmp, tmp_name, tmp_group;
    cin >> n;
    for(int i; i <= n; i++){
        getline(cin, tmp, '\n');
        tmp_name = tmp.substr(0, tmp.find(' '));
        tmp_group = tmp.substr(tmp.find(' ') + 1, tmp.length() - 1);
        if(l.is_empty()){l.push_back(tmp_name, tmp_group);}
        else{
            for(Node *i = l.first; i; i = i->next){
                if(i->next == nullptr){
                    l.push_back(tmp_name, tmp_group);
                    break;
                }
                else if (tmp_name < i->next->name){
                    try{
                    l.push_here(tmp_name, tmp_group, i);
                    break;
                    } catch(...){
                        throw push_error();
                    }
                }
            }
        }

    }
    l.print();
    Node* p = l.first;
    while (p) {
        string d = p->name + ' ' + p->group + '\n';
        fputs(d.c_str(), out_file);
        fwrite(d.c_str(), sizeof(d), 1, out_file_bin);
        p = p->next;
    }
    } catch(file_open_error){
        cerr << "Ошибка открытия файла";
    } catch(file_read_error){
        cerr << "Ошибка чтения файла";
    } catch(file_write_error){
        cerr << "Ошибка записи в файл";
    } catch(push_error){
        cerr << "Ошибка при добавлении элемента в список";
    }
}