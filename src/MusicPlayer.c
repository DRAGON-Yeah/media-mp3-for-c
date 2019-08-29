/*
 ============================================================================
 Name        : MusicPlayer.c
 Author      : DRAGON
 Version     :
 Copyright   : DRAGON-Yeah
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "audio/audioplayer.h"

static int music_index = 0;
int size = 4;
char *music[4] = {
		"/home/dragon/桌面/MusicPlayer/music/001.mp3",
		"/home/dragon/桌面/MusicPlayer/music/002.mp3",
		"/home/dragon/桌面/MusicPlayer/music/003.mp3",
		"/home/dragon/桌面/MusicPlayer/music/004.mp3",
};

VideoState *cur_stream = NULL;

void audio_finish_play(VideoState *is) {
	printf("-----------------------audio end-------------------\n\n");
	SDL_Delay(200);

	music_index++;
	int index = music_index % size;
	cur_stream = audio_play(index, 0);
}

void audio_play_fail(int code, char* error, VideoState *is) {
	printf("-----------------------audio fail:%s-------------------\n\n",
			error);
	music_index++;
	int index = music_index % size;
	cur_stream = audio_play(index, 0);
}

int main(int argc, char **argv) {
	audio_init();
	audioFinishCallback = &audio_finish_play;
	audioFailCallback   = &audio_play_fail;

	cur_stream = audio_play(music[0], 0);

	char cmd[100];
	while(fgets(cmd,100,stdin) != NULL){
		int len = strlen(cmd);
		if(len <= 2){
			if(strcmp(cmd,"q\n") == 0 || strcmp(cmd,"Q\n") == 0 ){//exit
				printf("...exit...\n");
				audio_exit(cur_stream);
				break;
			}else if(strcmp(cmd,"p\n")== 0 ||strcmp(cmd,"P\n") == 0){//pause
				printf("...pause...\n");
				audio_pause(cur_stream);
			}else if(strcmp(cmd,"s\n")== 0 ||strcmp(cmd,"S\n") == 0){//start
				audio_exit(cur_stream);
				SDL_Delay(200);
				printf("...start...\n");
				cur_stream = audio_play(music[0] , 0);
			}else if(strcmp(cmd,"r\n")== 0 ||strcmp(cmd,"R\n")== 0 ){//restart
				printf("...restart...\n");
			}else if(strcmp(cmd,"n\n")== 0 ||strcmp(cmd,"N\n")== 0 ){//next
				audio_exit(cur_stream);
				SDL_Delay(200);
				printf("...next...\n");
				music_index++;
				int index = music_index%size;
				cur_stream = audio_play(music[index] , 0);
			}else if(strcmp(cmd,"+\n")== 0){
				printf("...set volumn:%d...\n",5);
				audio_set_volumn(cur_stream,5);
			}else if(strcmp(cmd,"-\n")== 0){
				printf("...set volumn:%d...\n",-5);
				audio_set_volumn(cur_stream,-5);
			}
		}else{
			printf("...switch...\n");
		}
	}
	audio_quit();
	printf("--------------------------------------end , exit main thread----------------------------------\n");
	return EXIT_SUCCESS;
}
