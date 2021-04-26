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

//
#define MIN_DRINKING 0.2
#define MAX_DRINKING 0.8

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
//初始化,各个变量值
void init();
//红外检测模块
bool  infrared_detection(int level);
//重量检测
int weight_detection(int weight);
//酒精检测
int alcohol_testing(double alcoholContent);
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
 * 红外检测模块，根据高低电平判断是否有人
 * @param level
 * @return true 有人 ,@return 0 无人,其他电平结束程序
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

 /**
 * 重量检测模块，根据体重判断是否达到成人标准
  * @param weight
  * @return 1 成年人，0没有人，-1 儿童或者其他物体
 */
int weight_detection(int weight){
     if (weight >= ADULT_WEIGHT){
         return 1;
     }else if (weight < ADULT_WEIGHT && weight > 0){
         return -1;
     } else{
         return 0;
     }
 }
/**
 * 酒精检车模块，根据呼出气体中的含量判断是否饮酒驾驶
 * @param alcoholContent
 * @return 0 没有酒驾，1 饮酒驾驶， -1 醉驾
 */
int alcohol_testing(double alcoholContent){
    if (alcoholContent <MIN_DRINKING){
        return 0;
    } else if (alcoholContent > MIN_DRINKING && alcoholContent < MAX_DRINKING){
        return 1;
    } else{
        return -1;
    }
}
