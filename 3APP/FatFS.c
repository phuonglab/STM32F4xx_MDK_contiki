
#include "bsp.h"
#include "ff.h"
#include "string.h"

/*����BMP ��TXT�ļ�����Ŀ*/
unsigned char BMP_NUM=0; 
unsigned char TXT_NUM=0;
char TXT_Files[100][40];	//���100���ļ�,
char BMP_Files[100][40];	//���100���ļ�,
DIR dirs;
FILINFO finfo;
FATFS fs;
void Find_FileName(void)
{
	const char path[]="";
	unsigned short i;
	FRESULT res;

/*���ļ���֧��*/	
#if _USE_LFN
	static char lfn[_MAX_LFN * (_DF1S ? 2 : 1) + 1];
	finfo.lfname = lfn;
	finfo.lfsize = sizeof(lfn);
#endif


	/*�����ļ�ϵͳ*/
	res = f_mount(0, &fs);
	res=f_opendir(&dirs, path);

	if (res == FR_OK) {/*�������Ŀ¼�ɹ�*/
		
		while (f_readdir(&dirs, &finfo) == FR_OK){/*ͨ��dirs�������Ķ��ļ�����֪��ĩβ*/
			
			   	
			if(finfo.fattrib & AM_DIR){	 /*��Ŀ¼�ͽ�������ѭ��*/
				continue;	
			}
			if (finfo.fattrib & AM_ARC) { /*�մ򿪵��ļ������Ǵ浵�ļ�,*/
				
				if(!finfo.fname[0])	 break; /*�ļ�β������while*/		
				if(finfo.lfname[0]){/*���ļ���	*/
					i = (unsigned char )strlen(finfo.lfname);/*���ļ����ĳ��ȣ����֮��õ���׺*/

					if((finfo.lfname[i-3]=='t') && (finfo.lfname[i-2]=='x') && (finfo.lfname[i-1]=='t')){
						strcpy(TXT_Files[TXT_NUM],(const char *)finfo.lfname);
						TXT_NUM++;
					}
					else if((finfo.lfname[i-3]=='b') && (finfo.lfname[i-2]=='m') && (finfo.lfname[i-1]=='p')){
						strcpy(BMP_Files[BMP_NUM],(const char *)finfo.lfname);
						BMP_NUM++;
					}
				}
				else{	/*���ļ���*/
					i = (unsigned char )strlen(finfo.fname);/*���ļ����ĳ��ȣ����֮��õ���׺*/

					if((finfo.fname[i-3]=='t') && (finfo.fname[i-2]=='x') && (finfo.fname[i-1]=='t')){
						strcpy(TXT_Files[TXT_NUM],(const char *)finfo.fname);
						TXT_NUM++;
					}
					else if((finfo.fname[i-3]=='b') && (finfo.fname[i-2]=='m') && (finfo.fname[i-1]=='p')){
						strcpy(BMP_Files[BMP_NUM],(const char *)finfo.fname);
						BMP_NUM++;
					}	
				}
			}
		}	
	}
}

void dispalyfilename(void)
{
	unsigned char i;
	Find_FileName();
	for(i=0;i<BMP_NUM;i++){
		printf("\r\n%s",BMP_Files[i]);
//		lcd_display_string_line(0,i*16,0xf800,0,(unsigned char *)BMP_Files[i]);	
	}
	//��ʾ.txt�ļ�
	for(i=0;i<TXT_NUM;i++){
		printf("\r\n%s",TXT_Files[i]);
//		lcd_display_string_line(120,i*16,0xf800,0,(unsigned char *)TXT_Files[i]);	
	}

}
