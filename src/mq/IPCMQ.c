/*
 * IPCMQ.c
 *
 *  Created on: 2019年1月30日
 *      Author: dragon
 */

#include "IPCMQ.h"
#include "../cJson/cJSON.h"

/**
 * 初始化mq
 */
int ipc_mq_init(int msg_key){
	//建立消息队列
	int msgid = msgget((key_t) msg_key, 0666 | IPC_CREAT);
	if (msgid == -1) {
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		return -1;
	}
	return msgid;
}

/**
 * 发送播放信息给播放器
 */
int send_ipc_msg(int ipc_mq_pid,ipc_mq_msg data){
	if (msgsnd(ipc_mq_pid, (void*) &data, strlen(data.msg_data), 0) == -1) {
		fprintf(stderr, "msgsnd failed\n");
		return -1;
	}
	return 0;
}

/**
 * 删除消息队列
 */
int delete_ipc_msg(ipc_mq_st mq_st){
	mq_st.running = 0;
	if(msgctl(mq_st.mq_pid,IPC_RMID,0) == -1){
		fprintf(stderr,"msgctl failed :%d\n",errno);
		return -1;
	}
	return 0;
}

static int stop_recv_ipc_msg = 0;
void stop_recv(){
	stop_recv_ipc_msg = 1;
}

/**
 * 接收信息
 */
void run_ipc_mq_recv(ipc_mq_st *mq_st){
	ipc_mq_msg data;
	while(mq_st->running){
		if(stop_recv_ipc_msg){
			perror("stop recv ipc msg\n");
			break;
		}
		memset(data.msg_data,0,BUFSIZ);
		if(msgrcv(mq_st->mq_pid,(void*)&data,BUFSIZ,mq_st->mq_type,0) == -1){
//			fprintf(stderr,"msgrcv failed with error:%d\n",errno);
			continue;
		}
		printf("run_ipc_mq_recv -------------- data.msg_data:\n%s\n",data.msg_data);
		cJSON* respJson = cJSON_Parse(data.msg_data);
		if(respJson == NULL){
			perror("respJson is null \n");
			return;
		}
		char* url = cJSON_GetObjectItem(respJson,"url")->valuestring;
		if(url == NULL){
			perror("url is null \n");
		}
		double offset_time = cJSON_GetObjectItem(respJson,"offset_time")->valuedouble;
		int msg_id = cJSON_GetObjectItem(respJson,"msg_id")->valueint;

		mq_json_data json;
		json.msg_type = data.msg_type;
		json.url = url;
		json.offset_time = offset_time;
		json.msg_id = msg_id;
		ipcMqRecvMsgCallback(json);
	}
}

/**
 * 设置json
 */
char* set_ipc_mq_data(char* url,double offset_time,int msg_id){
	char tmp[256];
	sprintf(tmp,"{\"url\":\"%s\",\"offset_time\":%f,\"msg_id\":%d}",url,offset_time,msg_id);
	int len = strlen(tmp);
	char *data = (char*)malloc(len);
	memset(data,0,len);
	memcpy(data,tmp,len);
	return data;
}


