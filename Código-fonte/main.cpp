#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <dlp.h>


int main() {
	DLP *teste = new DLP();
	int err = teste->openDLP();
	int reg = 0x80;
	__s32 res;
	char buf[10];
	if (err == false){
		printf("Error: %d\n", teste->error);
	} else {
		printf("Sem erro ateh aki.%d\n", res);
		res = i2c_smbus_read_word_data(teste->kI2CFileDescriptor, 0x00);
		if (res < 0){
			printf("Erro de leitura.%d\n", res);
		} else{
			printf("Se pa deu certo.%d\n", res);
		}
		buf[0] = reg;
		buf[1] = 0x11;  // 0 -> HDMI 	1 -> Internal 	11-> test 	3 -> FPD
		//buf[2] = 0x65;
		
		while (write(teste->kI2CFileDescriptor, buf, 2) != 2){
			printf("Erro de escrita.\n");
		}// else{
			printf("Never Again.\n");
		//}
		reg = 0x8a;
		buf[0] = reg;
		buf[1] = 0x04;
		
		while (write(teste->kI2CFileDescriptor, buf, 2) != 2){
			//printf("Erro de escrita.2\n");
		} //else{
			printf("Yep. Always\n");
		//}
		/*printf("Entrando no modo de Input da memoria flash...\n");
		teste->writeDLP(0X80, 0x01);
		printf("Alterando Para Padrao 0x04...\n");
		teste->writeDLP(0X8a, 0x04);
		printf("JA REZOU?\n ENTAO VERIFIQUE SE DEU CERTO!\n");*/
		/*teste->writeDLP(128, 1);
		teste->writeDLP(138, 4);
		teste->writeDLP(0, 1);
		teste->writeDLP(10, 4);*/

		buf[0] = 0xc4;
		buf[1] = 0x00;
		buf[2] = 0x80; // 0xa0
		while (write(teste->kI2CFileDescriptor, buf, 3) != 3){
			//printf("Erro de escrita.\n");
		} /*else{
			printf("Se pa deu mais certo.\n");
		}*/
		
		buf[0] = 0xc1;
		buf[1] = 0x00;
		buf[2] = 0x00;
		buf[3] = 0x05;
		buf[4] = 0xb2;
		buf[5] = 0x55;
		buf[6] = 0x08;
		while (write(teste->kI2CFileDescriptor, buf, 7) != 7){
			printf("Erro de escrita.\n");
		}/* else{
			printf("Se pa deu mais certo.\n");
		}*/
		
		buf[0] = 0xc0;
		buf[1] = 0x80;
		while (write(teste->kI2CFileDescriptor, buf, 2) != 2){
			printf("Erro de escrita.\n");
		}/* else{
			printf("Se pa deu mais certo.\n");
		}*/
		

	}
	teste->closeDLP();
}

