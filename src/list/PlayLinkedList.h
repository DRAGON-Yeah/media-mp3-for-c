/*
 * PlayLinkedList.h
 *
 *  Created on: 2019年1月30日
 *      Author: dragon
 */

#ifndef LIST_PLAYLINKEDLIST_H_
#define LIST_PLAYLINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


//播放类型
enum MSG_TYPE{
	MSG_PLAY_START_W=1,//wakeup
	MSG_PLAY_SPEAK_URL,
	MSG_PLAY_STOP,
	MSG_PLAY_PAUSE,
	MSG_PLAY_START,
	MSG_PLAY_EXIT,
	MSG_PLAY_INIT_ALL,
	MSG_PLAY_INIT_NETWORK,
	MSG_SET_VOLUMN,
	MSG_AUDIO_END,
	MSG_AUDIO_INTERRUPT,
	MSG_AUDIO_EXCEPT
};
/**
 * 当前节点状态
 */
enum MSG_STATUS{
	MSG_STATUS_INIT=0,
	MSG_STATUS_PAUSE,
	MSG_STATUS_PLAYING,
	MSG_STATUS_STOP,
};

/**
 * 当前节点模式
 */
enum MSG_MODE{
	MSG_MODE_SEQUENCE=0,
	MSG_MODE_CYCLE
};


/**
 * 播放节点内容
 */
typedef struct PlayContent{
	long msg_id;//消息id
	enum MSG_TYPE msg_type;//消息类型
	int msg_index;//当前播放链表索引
	char* msg_url;//当前播放内容url
	char* msg_title;//当前播放内容标题
	char* msg_subtitle;//当前播放内容歌手/演讲者
	double msg_offsettime;//定位播放，被打断后重新播放使用
	enum MSG_STATUS msg_status;//当前节点播放状态
	enum MSG_MODE msg_mode;//当前节点播放模式
	int msg_err_times;//播放错误次数，3次则下一节点
}PlayContent;

/**
 * 播放链表节点
 */
typedef struct Node{
	PlayContent *playContent;
	struct Node *pNext;
}Node,*PlayNode;


/**
 * 创建空链表
 */
PlayNode create_empty_list();

/**
 * 遍历链表
 * @params headNode:头节点
 */
void traverse_list(PlayNode headNode);

/**
 * 插入节点
 * @params headNode:头节点
 * @params pos:插入节点位置
 * @params nodeContent:插入节点
 */
int insert_node(PlayNode headNode,int pos,PlayContent* nodeContent);

/**
 * 在结尾添加节点
 * @params headNode:头节点
 * @params insertNode:插入节点
 */
int add_node(PlayNode headNode,PlayContent* nodeContent);

/**
 * 求长度
 * @params headNode:头节点
 */
int get_node_len(PlayNode headNode);

/**
 * 插入节点
 * @params headNode:头节点
 * @params msg_index:删除节点索引
 */
int delete_node(PlayNode headNode,int msg_index);

/**
 * 获取节点
 * @params headNode:头节点
 * @params msg_index: 获取节点索引
 * @params destContent: 获取节点
 */
int get_node(PlayNode headNode,int msg_index,PlayContent** destContent);


/**
 * 清空列表
 * @params headNode:头节点
 */
int clear_node_list(PlayNode headNode);



#endif /* LIST_PLAYLINKEDLIST_H_ */
