#include "ANO_DT.h"
#include "headfile.h"

//使用匿名4.3上位机协议
/////////////////////////////////////////////////////////////////////////////////////
//数据拆分宏定义，在发送大于1字节的数据类型时，比如int16、float等，需要把数据拆分成单独字节进行发送

#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)    ) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )

unsigned char data_to_send[100];//缓冲


/////////////////////////////////////////////////////////////////////////////////////
//Send_Data函数是协议中所有发送数据功能使用到的发送函数
//移植时，用户应根据自身应用的情况，根据使用的通信方式，实现此函数

void ANO_DT_Send_Data(uint8 *dataToSend , uint8 length)
{
	
    uart_putbuff(UART_2,dataToSend,length);    //可以修改不同的串口发送数据
	
}
uint8 data_to_send[100];	//发送数据缓存

/*发送给上位机的数据协议*/
void ANO_DT_send_int16(float data1 , float data2, float data3, float data4, float data5,float data6, float data7,float data8,float data9,float data10,float data11,float data12,float data13,float data14,float data15)
{
    uint8 _cnt=0;
//        data_to_send[_cnt++] = 0xAA;      //匿名协议帧头  0xAAAA
//        data_to_send[_cnt++] = 0xAA;
//        data_to_send[_cnt++] = 0xF1;      //使用用户协议帧0xF1
//        data_to_send[_cnt++] = 38;        //1个short 长度 2个字节
    
//	    data_to_send[_cnt++]=BYTE3(data1);
//	    data_to_send[_cnt++]=BYTE2(data1);
//	    data_to_send[_cnt++]=BYTE1(data1);
//	    data_to_send[_cnt++]=BYTE0(data1);
//
//	    data_to_send[_cnt++]=BYTE3(data2);
//	    data_to_send[_cnt++]=BYTE2(data2);
//	    data_to_send[_cnt++]=BYTE1(data2);
//	    data_to_send[_cnt++]=BYTE0(data2);
//
//	    data_to_send[_cnt++]=BYTE3(data3);
//	    data_to_send[_cnt++]=BYTE2(data3);
//	    data_to_send[_cnt++]=BYTE1(data3);
//	    data_to_send[_cnt++]=BYTE0(data3);
//
//	    data_to_send[_cnt++]=BYTE3(data4);
//	    data_to_send[_cnt++]=BYTE2(data4);
//	    data_to_send[_cnt++]=BYTE1(data4);
//	    data_to_send[_cnt++]=BYTE0(data4);
//
//	    data_to_send[_cnt++]=BYTE3(data5);
//	    data_to_send[_cnt++]=BYTE2(data5);
//	    data_to_send[_cnt++]=BYTE1(data5);
//	    data_to_send[_cnt++]=BYTE0(data5);
//
//	    data_to_send[_cnt++]=BYTE3(data6);
//	    data_to_send[_cnt++]=BYTE2(data6);
//	    data_to_send[_cnt++]=BYTE1(data6);
//	    data_to_send[_cnt++]=BYTE0(data6);
//
//	    data_to_send[_cnt++]=BYTE3(data7);
//	    data_to_send[_cnt++]=BYTE2(data7);
//	    data_to_send[_cnt++]=BYTE1(data7);
//	    data_to_send[_cnt++]=BYTE0(data7);
//
//	    data_to_send[_cnt++]=BYTE3(data8);
//	    data_to_send[_cnt++]=BYTE2(data8);
//	    data_to_send[_cnt++]=BYTE1(data8);
//	    data_to_send[_cnt++]=BYTE0(data8);
//
//	    data_to_send[_cnt++]=BYTE3(data9);
//	    data_to_send[_cnt++]=BYTE2(data9);
//	    data_to_send[_cnt++]=BYTE1(data9);
//	    data_to_send[_cnt++]=BYTE0(data9);

//	    data_to_send[_cnt++]=BYTE3(data10);
//	    data_to_send[_cnt++]=BYTE2(data10);
//	    data_to_send[_cnt++]=BYTE1(data10);
//	    data_to_send[_cnt++]=BYTE0(data10);

	            data_to_send[_cnt++]=BYTE0(data1);
	            data_to_send[_cnt++]=BYTE1(data1);
	            data_to_send[_cnt++]=BYTE2(data1);
	            data_to_send[_cnt++]=BYTE3(data1);

	            data_to_send[_cnt++]=BYTE0(data2);
	            data_to_send[_cnt++]=BYTE1(data2);
	            data_to_send[_cnt++]=BYTE2(data2);
	            data_to_send[_cnt++]=BYTE3(data2);

	            data_to_send[_cnt++]=BYTE0(data3);
	            data_to_send[_cnt++]=BYTE1(data3);
	            data_to_send[_cnt++]=BYTE2(data3);
	            data_to_send[_cnt++]=BYTE3(data3);

	            data_to_send[_cnt++]=BYTE0(data4);
	            data_to_send[_cnt++]=BYTE1(data4);
	            data_to_send[_cnt++]=BYTE2(data4);
	            data_to_send[_cnt++]=BYTE3(data4);

	            data_to_send[_cnt++]=BYTE0(data5);
	            data_to_send[_cnt++]=BYTE1(data5);
	            data_to_send[_cnt++]=BYTE2(data5);
	            data_to_send[_cnt++]=BYTE3(data5);

                data_to_send[_cnt++]=BYTE0(data6);
                data_to_send[_cnt++]=BYTE1(data6);
                data_to_send[_cnt++]=BYTE2(data6);
                data_to_send[_cnt++]=BYTE3(data6);

                data_to_send[_cnt++]=BYTE0(data7);
                data_to_send[_cnt++]=BYTE1(data7);
                data_to_send[_cnt++]=BYTE2(data7);
                data_to_send[_cnt++]=BYTE3(data7);

                data_to_send[_cnt++]=BYTE0(data8);
                data_to_send[_cnt++]=BYTE1(data8);
                data_to_send[_cnt++]=BYTE2(data8);
                data_to_send[_cnt++]=BYTE3(data8);

                data_to_send[_cnt++]=BYTE0(data9);
                data_to_send[_cnt++]=BYTE1(data9);
                data_to_send[_cnt++]=BYTE2(data9);
                data_to_send[_cnt++]=BYTE3(data9);

                data_to_send[_cnt++]=BYTE0(data10);
                data_to_send[_cnt++]=BYTE1(data10);
                data_to_send[_cnt++]=BYTE2(data10);
                data_to_send[_cnt++]=BYTE3(data10);

                data_to_send[_cnt++]=BYTE0(data11);
                data_to_send[_cnt++]=BYTE1(data11);
                data_to_send[_cnt++]=BYTE2(data11);
                data_to_send[_cnt++]=BYTE3(data11);

                data_to_send[_cnt++]=BYTE0(data12);
                data_to_send[_cnt++]=BYTE1(data12);
                data_to_send[_cnt++]=BYTE2(data12);
                data_to_send[_cnt++]=BYTE3(data12);

                data_to_send[_cnt++]=BYTE0(data13);
                data_to_send[_cnt++]=BYTE1(data13);
                data_to_send[_cnt++]=BYTE2(data13);
                data_to_send[_cnt++]=BYTE3(data13);

                data_to_send[_cnt++]=BYTE0(data14);
                data_to_send[_cnt++]=BYTE1(data14);
                data_to_send[_cnt++]=BYTE2(data14);
                data_to_send[_cnt++]=BYTE3(data14);

                data_to_send[_cnt++]=BYTE0(data15);
                data_to_send[_cnt++]=BYTE1(data15);
                data_to_send[_cnt++]=BYTE2(data15);
                data_to_send[_cnt++]=BYTE3(data15);


	            data_to_send[_cnt++] = 0x00;      //匿名协议帧头  0xAAAA
	            data_to_send[_cnt++] = 0x00;
	            data_to_send[_cnt++] =0x80;
	            data_to_send[_cnt++] = 0x7f;        //1个short 长度 2个字节 0x80;      //使用用户协议帧0xF1




    
//    uint8 sum = 0;
//	for(uint8 i=0;i<_cnt;i++)
//	sum += data_t//o_send[i];
//	data_to_send[_cnt++]=sum;
	ANO_DT_Send_Data(data_to_send, _cnt);
}

