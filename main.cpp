#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
//int b[5][5]={{1,2,3,4,5},{3,6,4,7,8},{1,3,5,2,8},{9,0,6,4,2},{2,5,1,6,8}};
//int a[5]={5,7,3,9,2};
//int sum[5];
const int N=600;
int b[N][N];
int a[N];
long long sum[N];
void ordinary(int n)
{
    long long head, tail,freq ;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);
    int times=0;
    while(times<n)
    {
        for(int i = 0; i < N; i++)
        {
          sum[i]=0.0;
          for(int j = 0; j < N; j++)
            sum[i] += b[j][i] * a[j];
        }
         times++;
    }
    QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    cout<<(tail-head)*1000.0/(n*freq)<<"ms"<<endl;
//    for(int i=0;i<10;i++)cout<<"结果"<<sum[i]<<"   ";

}
void youhua(int n)
{
    long long head, tail,freq ;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);
     int times=0;
    while(times<n)
    {
        for(int i = 0; i < N; i++)
            sum[i] = 0.0;
        for(int j = 0; j < N; j++)
            for(int i=0;i<N;i++)
                sum[i] += b[j][i] * a[j];
        times++;
    }
    QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    cout<<(tail-head)*1000.0/(freq*n)<<"ms"<<endl;
//    for(int i=0;i<10;i++)cout<<"结果"<<sum[i]<<"   ";

}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            b[i][j]=i+j+1;
    }
    for(int i=0;i<N;i++)
        a[i]=i+1;
    int time[4]={1,50,100,200};
    for(int i=0;i<4;i++)
    {
        cout<<"n为"<<time[i]<<"时加速比"<<endl;
        ordinary(time[i]);
        youhua(time[i]);
    }
    return 0;
}




