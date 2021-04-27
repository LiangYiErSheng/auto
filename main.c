/**
 * ��Ƭ�����ܷ��Ƽݳ���
 * @return
 */
//��������,�����ж��Ƿ����
int weight;

//����������ͱ�׼
#define ADULT_WEIGHT 40

//�����ƽ���ߵ�ƽΪ1���͵�ƽΪ0
int level;

//�ƾ�����
double alcoholContent;

//��С�����������
#define MIN_DRINKING 0.2
#define MAX_DRINKING 0.8

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
//��ʼ��,��������ֵ
void init();
//������ģ��
bool  infrared_detection(int level);
//�������
int weight_detection(int weight);
//�ƾ����
int alcohol_testing(double alcoholContent);
//��������
//�Ͽ�����
//������ʾ
int main() {
    //��ʼ����������
    init();
    system("title ��Ƭ�����ܷ��Ƽݳ���");
    printf("�������ƽ����:\n");
    scanf(" %d",&level);
    //����level_parameter�����ܺ�����ķ���ֵ
    bool level_parameter;
    level_parameter=infrared_detection(level);

    if(level_parameter == true){
        printf("����������(kg):\n");
        scanf(" %d",&weight);
        //����weight_param,�������ؼ��ķ���ֵ
        int weight_param;
        weight_param=weight_detection(weight);

        if (weight_param == 1){
            //����alcohol_param,���ܾƾ���ⷵ��ֵ
            int  alcohol_param;
            printf("������ƾ�����(0~1):\n");
            scanf(" %lf",&alcoholContent);
            alcohol_param=alcohol_testing(alcoholContent);
            if (alcohol_param == 0){
                printf("û�кȾ�!\n");
            } else if (alcohol_param == 1){
                printf("���Ƽ�ʻ!\n");
            } else{
                printf("���!\n");
            }
        } else if (weight_param == 0){
            printf("��������!\n");
        } else{
            printf("����Ϊ��ͯ��������!\n");
        }
    } else if(level_parameter == false){
        printf("����û����!\n");
    }
    system("pause");
    return 0;
}

/**
 * ��ʼ������������ֵ
 * @return
 */
void init(){
    //��ʼ������Ϊ0
    weight = 0;
    //��ƽֵΪ0
    level = 0;
    //�ƾ�����Ϊ0
    alcoholContent = 0;
}

/**
 * ������ģ�飬���ݸߵ͵�ƽ�ж��Ƿ�����
 * @param level
 * @return true ���� ,@return 0 ����,������ƽ��������
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
 * �������ģ�飬���������ж��Ƿ�ﵽ���˱�׼
  * @param weight
  * @return 1 �����ˣ�0û���ˣ�-1 ��ͯ������������
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
 * �ƾ��쳵ģ�飬���ݺ��������еĺ����ж��Ƿ����Ƽ�ʻ
 * @param alcoholContent
 * @return 0 û�оƼݣ�1 ���Ƽ�ʻ�� -1 ���
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
