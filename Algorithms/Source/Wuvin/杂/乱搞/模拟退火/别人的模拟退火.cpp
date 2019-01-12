#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

struct pos{ double x, y; } *P, city[101];
int n;

///////// �����x���������֮�� /////////////
double dis(struct pos * x){
    double d = 0;
    for (P = city + n - 1; P >= city; P--)
        d += hypot(P->x - x->x, P->y - x->y);
    return d;
}

///////// ģ���˻� /////////////
double SA(){
    double t, min, tmp;     // �¶ȣ���С���룬��ʱ����
    struct pos p, tp;       // ���ŵ㣬��ʱ��
    int k = 0;                  // ��¼����δ���ܵ���

    p.x = p.y = 5000;       // ��ʼ�����ŵ�Ϊ���ĵ�
    min = dis(&p);          
    srand((unsigned)&t);

    ///// ��ʼ���¶ȣ��¶���һ�����ʼ�С���¶�С���ٽ磨1�� �� ��������һ��������20������ʱ��δ������ʱ ��ֹ /////
    for (t = 5000; t > 1 && k++ < 20; t *= .93){

        ///// ��p��Χһ�� ��Χ ��������ʱ�㣬 �÷�Χ���¶�t�����𽥼�С /////
        tp.x = p.x + (rand() & 1 ? 1 : -1) * rand()*t / RAND_MAX;
        tp.y = p.y + (rand() & 1 ? 1 : -1) * rand()*t / RAND_MAX;
        tmp = dis(&tp);

        ///// �����ɵ���ʱ�����С�ڵ�ǰ��С���������ŵ� /////
        ///// ������һ�� ���� ���ܸ���ʱ�㣬�ø������¶�t�����𽥼�С /////
        if (tmp < min || rand()*10000./RAND_MAX < t){
            p = tp;
            min = tmp;
            k = 0;
        }
    }
    return min;
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &city[i].x, &city[i].y);
    printf("%.0f\n", SA());
    return 0;
}
