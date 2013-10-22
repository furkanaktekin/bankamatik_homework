
//kullanıcı adı: furkan
//   şifre: 12253003                                
//        Furkan Aktekin 12253003

#include <stdio.h>     /*printf,scanf kodunun çalışması için*/
#include <string.h>     /*strcmp  kodunun çalışması için*/
#include <conio.h>   /*getch(); kodunun çalışması için*/

int main() 
{

	char kullanici_adi[50];    /*kullanıcı adını 50 karakterlik tanımladım*/
	char sifre[50];       /*şifreyi 50 karakterlik tanımladım*/
	int i;       /*menüdeki işlemlerin numarasını integer olarak tanımladım*/
	int yatirilacak_para;/*hesaba yatırılacak miktarı int olarak tanımladım*/
	int cekilecek_para; /*hesaptan çekilen miktarı int olarak tanımladım*/
	int gonderilecek_para;  /*hesaptan başka hesaba aktarılacak miktarı tanımladım*/
	int para_gonderilecek_hesap;  /*havale yapılacak hesabı tanımladım*/
	int bakiye=1000; /*hesabımdaki başlangıç param*/
	printf("\n\n");
	printf("Kullanici Adinizi Giriniz:");    /*kullanıcı adını istedim*/
	scanf("%s", &kullanici_adi);    /*klavyeden girilen değerler kullanıcı adına aktarılıyor*/


	if(!(strcmp(kullanici_adi, "furkan"))) /*programın çalışması için kullanıcı adı tanımladım*/
	{
		printf("\n\n");
		printf("Sifrenizi Giriniz:");  /*eğer kullanıcı adı furkan olarak girilirse program şifre isteyecek*/
		scanf("%s",sifre);
		if(!(strcmp("12253003",sifre)))     /*eğer şifre 12253003  ise karşımıza menü gelecek*/
		{
program_baslangic:      /*programda goto kullandım. goto başlangıcı*/
			printf("\n\n");
			printf("Hosgeldiniz\n\n");
			printf("MENU\n\n");      /*kullanıcı adını ve şifreyi doğru girince bu menü karşımıza gelecek*/
			printf("=========================================\n\n");
			printf("1)Hesabinizdaki Parayi Gormek Icin 1'e Basiniz.\n\n");
			printf("2)Hesabiniza Para Yatirmak Icin 2'ye Basiniz.\n\n");
			printf("3)Hesabinizdan Para Cekmek Icin 3'e Basiniz.\n\n");
			printf("4)Hesabinizdan Baska Hesaba Para Gondermek Icin 4'e Basiniz.\n\n");
			printf("5)Hesabinizdan Cikmak Icin 5'e Basiniz.\n\n");
			printf("Lutfen Yapmak Istediginiz Islemi Seciniz.\n\n");
			scanf("%d",&i);
			switch(i)
			{
			case 1:  /*eğer 1 e basılırsa bakiyemizi gösterecek*/
				printf("\n\n");
				printf("Bakiyeniz: %d TL",bakiye);
				printf("\n\n");
				printf("Menuye Geri Donmek Icin Bir Tusa Basiniz.\n\n");
				getch();
				goto program_baslangic;  /*bakiyeyi gördükten sonra bir tuşa basılırsa menü tekrar gözükecek*/
				break;

			case 2:
				printf("\n\n");
				printf("Yatirilacak Miktar(TL):");  /*eğer 2 ye basılırsa hesaba para yatırma işlemi gerçekleşir*/
				scanf("%d",&yatirilacak_para); 
				bakiye+=yatirilacak_para;
				printf("\n\n");
				printf("Paraniz Hesabiniza Yatirilmistir.\n\n"); 
				printf("Yeni Bakiyeniz: %d TL\n",bakiye);   
				printf("\n\n");
				printf("Menuye Geri Donmek Icin Bir Tusa Basiniz.\n\n");  /*parayı hesaba yatırdıktan sonra ve yeni bakiyeyi gördükten sonra bir tuşa basılarak menüye dönülür*/
				getch();
				goto program_baslangic;
				break;

			case 3:
				printf("\n\n");
				printf("Cekilecek para miktari(TL):"); /*eğer 3 e basılırsa para çekme gerçekleşir*/
				scanf("%d",&cekilecek_para); 
				if(cekilecek_para<bakiye)     /*bakiyemizden az para çekmek istiyorsak bu işlem gerçekleşir*/
				{
					printf("\n\n");
					printf("Cekilen para miktari: %d  TL\n",cekilecek_para);
					bakiye=(bakiye)-(cekilecek_para);
					printf("\n\n");
					printf("Hesabinizda %d TL kalmistir.\n",bakiye);
					printf("\n\n");
					printf("Menuye Geri Donmek Icin Bir Tusa Basiniz.\n\n");
					getch();
					goto program_baslangic;
				}
				else
				{
					printf("\n\n");
					printf("Bakiyenizden Fazla Miktarda Para Cekemezsiniz.");    /*ama bakiyemizden fazla miktarda para çekmek istersek hata mesajı veriyorum*/
					printf("\n\n");
					printf("Menuye Geri Donmek Icin Bir Tusa Basiniz.\n\n");
					getch();
					goto program_baslangic;
				}
				break;

			case 4:
				printf("\n\n");
				printf("Para Gondermek Istediginiz Hesap Numarasini Yaziniz:");  /*eğer 4 e basılırsa başka hesaba para gönderme işlemi gerçekleşir.*/
				printf("\n\n");
				scanf("%d",&para_gonderilecek_hesap);   /*klavyeden girilen hesap numarası para gönderilecek hesap numarasına aktarılıyor*/
				printf("Gonderilecek para miktarini yaziniz(TL):");
				scanf("%d",&gonderilecek_para); 
				if(gonderilecek_para<bakiye)  /*eğer gönderilecek miktar bakiyemizden az ise bu işlem gerçekleşir.*/
				{
					printf("\n\n");
					printf("Gonderilen para miktari: %d  TL\n",gonderilecek_para);
					bakiye=(bakiye)-(gonderilecek_para);
					printf("\n\n");
					printf("%d Numarali Hesaba %d TL Gonderilmistir.\n\n",para_gonderilecek_hesap,gonderilecek_para);
					printf("Hesabinizda %d TL kalmistir.\n\n",bakiye);
					printf("Menuye Geri Donmek Icin Bir Tusa Basiniz.\n\n");
					getch();
					goto program_baslangic;
				}
				else
				{
					printf("\n\n");
					printf("Bakiyenizden Fazla Miktarda Para Gonderemezsiniz.");   /*ama gönderilecek miktar bakiyemizden fazla ise hata mesajı verdiriyorum*/
					printf("\n\n");
					printf("Menuye Geri Donmek Icin Bir Tusa Basiniz.\n\n");
					getch();
					goto program_baslangic;
				}
				break;

			default:
				printf("1,2,3,4,5 disinda bir sayi girdiniz.\n\n");   /*menüde 1,2,3,4,5  sayılarından farklı bir değer girilirse hata mesajı verdiriyorum*/
				printf("Lutfen Bir Tusa Basip Menuye Geliniz.\n\n");
				getch();
				goto program_baslangic;
				break;

			case 5:
				printf("\n\n");
				printf("Iyi Gunler"); /* eğer 5 e basılırsa programdan çıkılıyor*/

			}
		}

		else
		{
			printf("\n\n");
			printf("Sifreniz Hatali.Guvenlik Geregi Sistemi Kapatiyoruz :)");  /*şifre hatalı ise burada hata mesajı verdiriyorum*/
		}
	}
	else
	{
		printf("\n\n");
		printf("Kullanici Adiniz Hatali.Guvenlik Geregi Sistemi Kapatiyoruz :)");  /*kullanıcı adı hatalı ise burada hata mesajı verdiriyorum*/
	}
	getch();    /*program bir tuşa basmamı bekliyor*/
}
