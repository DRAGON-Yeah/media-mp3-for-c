/*
 * IPCMQ.h
 *
 *  Created on: 2019年1月30日
 *      Author: dragon
 */

#ifndef MQ_IPCMQ_H_
#define MQ_IPCMQ_H_

#include "../list/PlayLinkedList.h"

#include <errno.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

/**
 * 消息队列初始化结构
 */
typedef struct ipc_mq_st{
	int mq_key;
	int mq_pid;
	int mq_type;
	int running;
}ipc_mq_st;

/**
 * 消息队列结构体
 */
typedef struct ipc_mq_msg{
	long int msg_type;
	char msg_data[BUFSIZ];
}ipc_mq_msg;

/**
 * json数据
 */
typedef struct mq_json_data{
	long int msg_type;
	char* url;
	double offset_time;
	int msg_id;
}mq_json_data;



//mq回调
void (*ipcMqRecvMsgCallback)(mq_json_data json);
void ipc_mq_recv_msg_callback(mq_json_data json);



/**
 * 初始化mq
 */
int ipc_mq_init(int msg_key);

/**
 * 发送播放信息给播放器
 */
int send_ipc_msg(int ipc_mq_pid,ipc_mq_msg data);

/**
 * 删除消息队列
 */
int delete_ipc_msg(ipc_mq_st mq_st);

void stop_recv();
/**
 * 接收信息
 */
void run_ipc_mq_recv(ipc_mq_st *mq_st);

/**
 * 设置json
 */
char* set_ipc_mq_data(char* url,double offset_time,int msg_id);


#endif /* MQ_IPCMQ_H_ */
