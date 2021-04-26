/**
 * 单片机智能防酒驾程序
 * @return
 */
//定义体重,用于判断是否成人
int weight;

//成人体重最低标准
#define ADULT_WEIGHT 40

//定义电平，高电平为1，低电平为0
int level;

//酒精含量
double alcoholContent;

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
//初始化,各个变量值
void init();
//红外检测模块
bool  infrared_detection(int level);
//重量检测
//酒精检测
//允许启动
//断开动作
//报警提示
int main() {
    init();
    printf("Hello, World!\n");
    return 0;
}

/**
 * 初始化各个参数的值
 * @return
 */
void init(){
    //初始化体重为0
    weight = 0;
    //电平值为0
    level = 0;
    //酒精含量为0
    alcoholContent = 0;
}

/**
 * 人体检测模块，根据高低电平判断是否有人
 * @return
 */
 bool infrared_detection(int level){
     if ( level == 1){
         return true;
     } else if (level == 0){
         return false;
     } else{
         exit(-1);
     }
 }