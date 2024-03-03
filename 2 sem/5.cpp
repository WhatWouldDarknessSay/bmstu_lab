#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
struct Node {
    string val;
    Node* next;
    Node(string _val) : val(_val), next(nullptr){}
};

struct list {
    Node* first;
    Node* last;
    bool is_empty() {
        return first == nullptr;
    }
    list() : first(nullptr), last(nullptr) {}

    void push_back(string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void push_here(string _val, Node* p){
        Node* n = new Node(_val);
        n->next = p->next;
        p->next = n;
    }
    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main(){
    list l;
    FILE* in_file= fopen("5_input.txt", "r");
    FILE *out_file= fopen("5_output.txt", "w");
    while (!feof(in_file)){
        string word = "";
        int ch;
        while(((ch = fgetc(in_file)) != EOF) && (ch != ' ')){
            word += ch;
        }
        if(l.is_empty()){l.push_back(word);}
        else{
            for(Node *i = l.first; i; i = i->next){
                if (i->next == nullptr || word < i->next->val){
                    // l.push_here(word, i);
                    Node* n = new Node(word);
                    n->next = i->next;
                    i->next = n;
                    break;
                }
            }
        }

        // if(true){
        //     word += "; digits: " + to_string(counter) + '\n';
        //     fputs(word.c_str(), out_file);
        // }
    }
    l.print();
    Node* p = l.first;
    while (p) {
        string d = p->val + ' ';
        fputs(d.c_str(), out_file);
        p = p->next;
    }
}