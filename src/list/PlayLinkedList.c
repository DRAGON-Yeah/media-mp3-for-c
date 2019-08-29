/*
 * PlayLinkedList.c
 *
 *  Created on: 2019年1月30日
 *      Author: dragon
 */

#include "PlayLinkedList.h"


/**
 * 创建链表
 */
PlayNode create_empty_list(){
	PlayNode pHead = (PlayNode)malloc(sizeof(Node));//头节点
	PlayNode pTail   = pHead;//尾节点
	pTail->pNext = NULL;
	return pHead;
}

/**
 * 遍历链表
 * @params headNode:头节点
 */
void traverse_list(PlayNode headNode){
	if(headNode == NULL){
		perror("headNode is null\n");
		return;
	}
	PlayNode pNode = headNode->pNext;
	while(pNode != NULL){
		PlayContent *playContent = pNode->playContent;
		printf("msg_id:%ld，msg_type:%d，msg_index:%d，msg_url:%s，msg_title:%s，msg_subtitle:%s，msg_offsettime:%f，msg_status:%d，msg_mode:%d，msg_err_times:%d\n"
				,playContent->msg_id,playContent->msg_type,playContent->msg_index,playContent->msg_url,playContent->msg_title,playContent->msg_subtitle,playContent->msg_offsettime,
				playContent->msg_status,playContent->msg_mode,playContent->msg_err_times);
		pNode = pNode->pNext;
	}
}

/**
 * 插入节点
 * @params headNode:头节点
 * @params pos:插入节点位置
 * @params nodeContent:插入节点
 */
int insert_node(PlayNode headNode,int pos,PlayContent* nodeContent){

	if(headNode == NULL){
		perror("headNode is null\n");
		return -1;
	}

	if(nodeContent == NULL){
		perror("nodeContent is null\n");
		return -1;
	}

	if(pos < 0){
		perror("pos < 0\n");
		return -1;
	}

	int i = 0;
	PlayNode _node = headNode;
	PlayNode pSwap;

	while(i < pos-1){
		_node = _node->pNext;
		i++;
	}
	PlayNode newNode = (PlayNode)malloc(sizeof(Node));
	newNode->playContent = nodeContent;
	/*
	newNode->playContent = (PlayContent*)malloc(sizeof(PlayContent));

	newNode->playContent->msg_id = nodeContent->msg_id;
	newNode->playContent->msg_type = nodeContent->msg_type;
	newNode->playContent->msg_index = nodeContent->msg_index;


	if(nodeContent->msg_url != NULL){
		int len = strlen(nodeContent->msg_url);
		newNode->playContent->msg_url = (char*)malloc(len);
		memset(newNode->playContent->msg_url,0,len);
		memcpy(newNode->playContent->msg_url,nodeContent->msg_url,len);
	}
	if(nodeContent->msg_title != NULL){
		int len = strlen(nodeContent->msg_title);
		newNode->playContent->msg_title = (char*)malloc(len);
		memset(newNode->playContent->msg_title,0,len);
		memcpy(newNode->playContent->msg_title,nodeContent->msg_title,len);
	}
	if(nodeContent->msg_subtitle != NULL){
		int len = strlen(nodeContent->msg_subtitle);
		newNode->playContent->msg_subtitle = (char*)malloc(len);
		memset(newNode->playContent->msg_subtitle,0,len);
		memcpy(newNode->playContent->msg_subtitle,nodeContent->msg_subtitle,len);
	}

	newNode->playContent->msg_offsettime = nodeContent->msg_offsettime;
	newNode->playContent->msg_status = nodeContent->msg_status;
	newNode->playContent->msg_mode = nodeContent->msg_mode;
	newNode->playContent->msg_err_times = nodeContent->msg_err_times;
	 */

	pSwap = _node->pNext;
	_node->pNext = newNode;
	newNode->pNext = pSwap;
	return 0;
}


/**
 * 在结尾添加节点
 * @params headNode:头节点
 * @params insertNode:插入节点
 */
int add_node(PlayNode headNode,PlayContent* nodeContent){
	if(headNode == NULL){
		perror("headNode is null\n");
		return -1;
	}

	if(nodeContent == NULL){
		perror("nodeContent is null\n");
		return -1;
	}

	int i = 0;
	int len = get_node_len(headNode);
	PlayNode pNode = NULL;
	if(len>0){
		pNode = headNode->pNext;
		for (i = 0; i < len - 1; i++) {
			pNode = pNode->pNext;//获取前一个节点
		}
	}else{
		pNode = headNode;
	}

	PlayNode newNode = (PlayNode)malloc(sizeof(Node));
	//newNode->playContent = (PlayContent*)malloc(sizeof(PlayContent));
	newNode->playContent = nodeContent;
	/*
	newNode->playContent->msg_id = nodeContent->msg_id;
	newNode->playContent->msg_type = nodeContent->msg_type;
	newNode->playContent->msg_index = nodeContent->msg_index;

	if(nodeContent->msg_url != NULL){
		int len = strlen(nodeContent->msg_url);
		newNode->playContent->msg_url = (char*)malloc(len);
		memset(newNode->playContent->msg_url,0,len);
		memcpy(newNode->playContent->msg_url,nodeContent->msg_url,len);
	}
	if(nodeContent->msg_title != NULL){
		int len = strlen(nodeContent->msg_title);
		newNode->playContent->msg_title = (char*)malloc(len);
		memset(newNode->playContent->msg_title,0,len);
		memcpy(newNode->playContent->msg_title,nodeContent->msg_title,len);
	}
	if(nodeContent->msg_subtitle != NULL){
		int len = strlen(nodeContent->msg_subtitle);
		newNode->playContent->msg_subtitle = (char*)malloc(len);
		memset(newNode->playContent->msg_subtitle,0,len);
		memcpy(newNode->playContent->msg_subtitle,nodeContent->msg_subtitle,len);
	}

	newNode->playContent->msg_offsettime = nodeContent->msg_offsettime;
	newNode->playContent->msg_status = nodeContent->msg_status;
	newNode->playContent->msg_mode = nodeContent->msg_mode;
	newNode->playContent->msg_err_times = nodeContent->msg_err_times;
	 */

	pNode->pNext = newNode;
	newNode->pNext = NULL;

	return 0;
}

/**
 * 求长度
 * @params headNode:头节点
 */
int get_node_len(PlayNode headNode){
	if(headNode == NULL){
		perror("headNode is null\n");
		return -1;
	}
	int len = 0;
	PlayNode pNode = headNode->pNext;
	while(pNode != NULL){
		len++;
		pNode = pNode->pNext;
	}
	return len;
}


/**
 * 插入节点
 * @params headNode:头节点
 * @params msg_index:删除节点索引
 */
int delete_node(PlayNode headNode,int msg_index){
	if(headNode == NULL){
		perror("headNode is null'\n");
		return -1;
	}

	if(msg_index < 0){
		perror("msg_index < 0\n");
		return -1;
	}

	PlayNode _node = headNode;
	PlayNode pSwap;

	if(_node->pNext == NULL){
		perror("headNode->pNext == NULL1\n");
		return -1;
	}
	int i = 0;

	while( i < msg_index-1 ){
		_node =_node->pNext;
		i++;
	}

	pSwap = _node->pNext;

	/*
	PlayContent* content = pSwap->playContent;
	PlayContent* deleteContent = (PlayContent*)malloc(sizeof(PlayContent));

	deleteContent->msg_id = content->msg_id;
	deleteContent->msg_type = content->msg_type;
	deleteContent->msg_index = content->msg_index;

	if(content->msg_url != NULL){
		int len = strlen(content->msg_url);
		deleteContent->msg_url = (char*)malloc(len);
		memset(deleteContent->msg_url,0,len);
		memcpy(deleteContent->msg_url,content->msg_url,len);
	}
	if(content->msg_title != NULL){
		int len = strlen(content->msg_title);
		deleteContent->msg_title = (char*)malloc(len);
		memset(deleteContent->msg_title,0,len);
		memcpy(deleteContent->msg_title,content->msg_title,len);
	}
	if(content->msg_subtitle != NULL){
		int len = strlen(content->msg_subtitle);
		deleteContent->msg_subtitle = (char*)malloc(len);
		memset(deleteContent->msg_subtitle,0,len);
		memcpy(deleteContent->msg_subtitle,content->msg_subtitle,len);
	}

	deleteContent->msg_offsettime = content->msg_offsettime;
	deleteContent->msg_status    = content->msg_status;
	deleteContent->msg_mode    = content->msg_mode;
	deleteContent->msg_err_times = content->msg_err_times;
	 */
	_node->pNext = _node->pNext->pNext;
	free(pSwap->playContent->msg_url);
	free(pSwap->playContent->msg_title);
	free(pSwap->playContent->msg_subtitle);
	free(pSwap->playContent);
	free(pSwap);
	return 0;
}

/**
 * 获取节点
 * @params headNode:头节点
 * @params msg_index: 获取节点索引
 * @params destContent: 获取节点
 */
int get_node(PlayNode headNode,int msg_index,PlayContent** destContent){
	printf("get_node---------------msg_index:%d\n",msg_index);
	if(headNode == NULL){
		perror("headNode is null\n");
		return -1;
	}

	if(msg_index < 0){
		perror("msg_index < 0\n");
		return -1;
	}

	int flag = 0;
//	PlayContent* destContent = NULL;
	PlayNode pNode = headNode->pNext;
	while(pNode != NULL){
		PlayContent *content = pNode->playContent;
		int index = content->msg_index;
		if(index == msg_index){
			flag = 1;
			*destContent = content;
			printf("get_node---------------msg_url:%s\n",(*destContent)->msg_url);
			/*
			destContent = (PlayContent*)malloc(sizeof(PlayContent));

			destContent->msg_id = content->msg_id;
			destContent->msg_type = content->msg_type;
			destContent->msg_index = content->msg_index;

			if(content->msg_url != NULL){
				int len = strlen(content->msg_url);
				destContent->msg_url = (char*)malloc(len+1);
				memset(destContent->msg_url,0,len+1);
				memcpy(destContent->msg_url,content->msg_url,len);
			}
			if(content->msg_title != NULL){
				int len = strlen(content->msg_title);
				destContent->msg_title = (char*)malloc(len);
				memset(destContent->msg_title,0,len);
				memcpy(destContent->msg_title,content->msg_title,len);
			}
			if(content->msg_subtitle != NULL){
				int len = strlen(content->msg_subtitle);
				destContent->msg_subtitle = (char*)malloc(len);
				memset(destContent->msg_subtitle,0,len);
				memcpy(destContent->msg_subtitle,content->msg_subtitle,len);
			}

			destContent->msg_offsettime = content->msg_offsettime;
			destContent->msg_status    = content->msg_status;
			destContent->msg_mode    = content->msg_mode;
			destContent->msg_err_times = content->msg_err_times;
			 */
			break;
		}
		pNode = pNode->pNext;
	}

	if(flag == 1){
		return 0;
	}
	return -1;
}


/**
 * 清空列表
 * @params headNode:头节点
 */
int clear_node_list(PlayNode headNode) {
	if (headNode == NULL) {
		perror("headNode is null\n");
		return -1;
	}
	PlayNode p = headNode->pNext;
	PlayNode q;
	while (p != NULL) {
		q = p->pNext; //q指向p的下一个节点
		free(p->playContent->msg_url);
		p->playContent->msg_url = NULL;
		free(p->playContent->msg_title);
		p->playContent->msg_title = NULL;
		free(p->playContent->msg_subtitle);
		p->playContent->msg_subtitle = NULL;
		free(p->playContent); //清楚p的内容
		p->playContent = NULL;
		free(p);//释放p
		p = q;//移动p
	}
	headNode->pNext = NULL;
	return 0;
}





