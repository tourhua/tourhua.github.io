﻿/*
    实验名称：实验3  递归下降语法分析程序设计
*/
#include <bits/stdc++.h>
using namespace std;
//#pragma warning(disable:4996)

char str[10];
int index = 0;
void E();  // E->TX;
void X();  // X->+TX | e
void T();  // T->FY
void Y();  // Y->*FY | e
void F();  // F->(E) | i
int main() {
    int len;
    int m;
    cout << "请输入算术表达式：" << endl;
    scanf("%s", str);
    len = strlen(str);
    str[len] = '#';
    str[len + 1] = '\0';
    E();
    if (str[index] == '#')
        printf("正确语句！\n");
    else {
        printf("分析失败!\n");
    }
    strcpy(str, "");
    index = 0;
    return 0;
}
void E() {
    T();
    X();
}
void X() {
    if (str[index] == '+') {
        index++;
        T();
        X();
    }
}
void T() {
    F();
    Y();
}
void Y() {
    if (str[index] == '*') {
        index++;
        F();
        Y();
    }
}
void F() {
    if (str[index] == 'i') {
        index++;
    }
    else if (str[index] == '(') {
        index++;
        E();
        if (str[index] == ')') {
            index++;
        }
        else {
            printf("分析失败!\n");
            exit(0);
        }
    }
    else {
        printf("分析失败!\n");
        exit(0);
    }
}