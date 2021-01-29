#include <screen.h>
#include <kshell.h>
#include <timer.h>
#include <ports.h>
#include "./lib/string.h"

extern int enable_shell;

void kshell_init(){
	kprintf("Enabling kernel shell...");
	enable_shell = 1;
	putstr("[DONE]\n", COLOR_GRN, COLOR_BLK);
}

void kshell(char s[], int i){
  if(strcmp(s, "clear")==0){
  	clear_scr();
  }
  else if(strcmp(s, "help")==0){
  	available_commands();
  }
  else if(strcmp(s, "about")==0){
  	kprintf("hos-x86 a 32 bit operating system written in C and Assembly\n");
  }
  else if(strcmp(s, "hlt")==0){
  	halt();
  }
  else if(strcmp(s, "reboot")==0){
  	reboot();
  }
  else{
  	unknown_command(s);
  }

  for(int j=0; s[j]!='\0'; j++){
  	s[j]='\0';
  }
  kprintf(">");
}

void halt(){
  	kprintf("Halting system...");
  	putstr("[DONE]", COLOR_GRN, COLOR_BLK);
  	asm volatile("hlt");
}

void reboot(){
  	kprintf("Rebooting...\n");
  	//using 8042 keyboard controller to pulse the CPU's RESET Pin
  	unsigned char temp = 0x02;
  	while(temp & 0x02)
  		temp = in_port_byte(0x64);
  	out_port_byte(0x64, 0xFE);
  	asm volatile("hlt");	
}

void clear_scr(){
	clear(COLOR_WHT, COLOR_BLK);
	set_cursor_pos(0,0);
}

void available_commands(){
    kprintf("Available commands:");
  	putstr("\n\thelp\tclear\tabout\n\thlt\treboot\n", COLOR_GRN, COLOR_BLK);
}

void unknown_command(char s[]){
	kprintf(s);
  	putstr(" : command not found!\n", COLOR_RED, COLOR_BLK);
  	putstr("Type ", COLOR_GRY, COLOR_BLK);
  	putstr("\"help\" ", COLOR_YEL, COLOR_BLK);
  	putstr("for the list of available commands.\n", COLOR_GRY, COLOR_BLK);
}