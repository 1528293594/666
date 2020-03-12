#include<stdio.h>
#include<time.h>


int main()
{
	//*****************************张君豪部分**************************// 
	int mons[12];//定义数组储存每个月的天数 
	int year,mon,day,nsum,sum1,q,w,dsum=0,now,n,k,j,sum2,sum,i2,j2,k2,nowmon,nowday;//出生年，月，日，月份储存，日期储存，生日到1.1的天数，测定日到1.1天数； 
	
		/*****利用库函数获取本地时间******/ 
	struct tm *p;    //该结构体带有时间信息转换的函数 
	time_t t;       //表示日历时间 
	time(&t);       //用time函数获取时间 
	p=localtime(&t);//获取本地时间 
	
	nowmon=(p->tm_mon)+1;
	nowday=(p->tm_mday);
	now=(p->tm_year)+1900; 
	
	printf("今天是%d年%d月%d日\n",now,nowmon,nowday);
	printf("请输入生日(年月日以空格隔开)：");
	scanf("%d %d %d",&year,&mon,&day);
	
	
	nsum=(p->tm_yday)+1; //从1.1到今天第几天转换成共有多少天 
	printf("测定日到1.1共有%d天\n",nsum); //打印检验数字是否正确，正式合并删去 
	
	
	/*算生日到1.1的天数 */ 
	 if (year%4==0&& year%100!=0)    //闰年情况 
	{
		int mons[12]={31,29,31,30,31,30,31,31,30,31,30,31};
		q=mon;w=day;
		for(q=0;q<mon-1;q++)
		{
			dsum+=mons[q];     //每个月求和 
		}
		dsum+=w;  //加上日期 
		printf("生日到1.1一共%d天\n",dsum); //printf输出dsum检验天数对不对 
	}else //平年情况 
	{
		int mons[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		q=mon;w=day;
		for(q=0;q<mon-1;q++)
		{
			dsum+=mons[q];
		}
		dsum+=w;
		printf("生日到1.1一共%d天\n",dsum);
	}
	sum1=nsum-dsum;   //1.1至测定天数-1.1至生日天数
	
	
	//************************颜胜部分**********************************// 
	j=year;
	n=j%4;          /*年份取余*/
	switch(n)  /*余数的大小*/
	{
	case 0:
		for(k=0;j<now;j=j+4,k++)   /*余数为0，出生年月是闰年，后面一次加四，有多少个四，就有多少个闰年*/
	         if(j%100!=0||j%400==0)  /*当年数中有一百的倍数减一，四百的倍数后面k不变*/
			      k=k;
			 else
				 k=k-1;
			    break;
	case 1: j=j+3;                       /*余数为1，先加个三，闰年，后面是闰年，后面一次加四，有多少个四，就有多少个闰年*/
		for(k=0;j<=now;j=j+4,k++)
		   if(j%100!=0||j%400==0)              /*当年数中有一百的倍数减一，有四百的倍数就不变*/
		    k=k;
	    	else                           
		  k=k-1;  
		    break;
	case 2:  j=j+2;                              /*余数为2，先加个二，是闰年，后面一次加四，有多少个四，就有多少个闰年*/
		for(k=0;j<=now;j=j+4,k++)
	       if(j%100!=0||j%400==0)                           /*当年数中有一百的倍数减一，有四百的倍数就不变*/
		    k=k;
		   else 
			k=k-1;                                
		   break;
	case 3:  j=j+1;
 		for(k=0;j<=now;j=j+4,k++)                 /*余数为3，  先加个一 ， 是闰年，后面一次加四，有多少个四，就有多少个闰年*/   
	       if(j%100!=0||j%400==0)                            /*当年数中有一百的倍数减一，有四百的倍数就不变*/
		    k=k;
		   else                                                    
		   k=k-1;
		    break;
	
	}
		
	sum2=(now-year)*365+k;        
	printf("所经历总天数为%d\n",sum2);
	
	sum=sum1+sum2;
	
	//********************************苏贵雨部分***************************// 
	i2=sum%23;/*计算i2的值*/ 
	j2=sum%28;/*计算j2的值*/ 
	k2=sum%33;/*计算k2的值*/
	//判断体力处在什么时期 
	if(i2==0)
	{
		printf("体力处在周期日\n"); 
	 } 
	 else if(i2>0&&i2<12)
	 {
	 	printf("体力处在高潮期第%d天\n",i2);
	 }
	 else if(i2==12)
	 {
	 	printf("体力处在临界日\n");
	 }
	 else if(i2>12&&i2<23)
	 {
	 	i2-=12;
	 	printf("体力处在低潮期第%d天\n",i2);
	 }
	 //判断情绪处在什么时期 
	 if(j2==0)
	 {
	 printf("情绪处在周期日\n");
    }
    else if(j2>0&&j2<14)
    {
    	printf("情绪处在高潮期第%d天\n",j2);
	}
	else if(j2==14)
	{
		printf("情绪处在临界日\n");
	}
	else if(j2>14&&j2<28)
	{
		j2-=14;
		printf("情绪处在低潮期第%d天\n",j2); 
	}
	//判断智力处在什么时期 
	if(k2==0)
	{
		printf("智力处在周期日\n");
	}
	else  if(k2>0&&k2<17)
	{
		printf("智力处在高潮期第%d天\n",k2); 
	}
	else if(k2==17)
	{
		printf("智力处在临界日\n");
	}
	else if(k2>17&&k2<33)
	{
		k2-=17;
		printf("智力处在低潮期第%d天\n",k2);
	} 
	 
	return 0; 
	
} 


