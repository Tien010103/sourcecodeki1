#include <iostream>
#include <conio.h>
#include<math.h>
#include<string>
#include<cstring>
#define Max 100 
using namespace std;
typedef int item;
int checksonguyen(char *a);
int chuyenkieu(char *s);
struct Stack{ //cau truc stack
	int Top; 
	item Data[Max];
};
//a
void Init (Stack &S) //ham khoi tao
{
	S.Top = 0;
}

int Isempty(Stack S) //ham kiem tra rong
{
	return (S.Top == 0);
}

int Isfull(Stack S) //ham kiem tra day
{
	return (S.Top == Max); 
}

void Push(Stack &S, item x) //ham them phan tu vao top
{
	if (!Isfull(S))//neu chua day thi thuc hien thao tac them
	{
		S.Data[S.Top] = x;//them vao vi tri dinh stack
		S.Top ++; //sau khi them, tang bien Top len 1 don vi
	}
	else{
		cout<<"\nStack da day";
	}
}
int Pop(Stack &S) //ham xoa phan tu top
{
	if (!Isempty(S))//neu chua rong thi thuc hien thao tac xoa
	{
		S.Top --;//giam bien Top(xoa dinh)
		return S.Data[S.Top];//tra ve Top 
	}
	else{
		cout<<"\nStack da rong";
	}
}
void Input (Stack &S) //nhap du lieu cho stack
{
	int val;
	item x;
	char s[100];
	do{
		cout<<"Nhap so luong phan tu cua stack: ";
		cin.getline(s,100);
		if(!checksonguyen(s)){
			cout<<"Khong hop le, nhap dung so nguyen!\n";
		}
		else{
			val=chuyenkieu(s);
		}
		if(val<1 || val>Max){
			cout<<"Nhap lai! (1->100)\n";
		}
	}
	while(!checksonguyen(s) || val<1 || val>Max);
	for(int i=0;i<val;i++){
	do{
		cout<<"Nhap phan tu thu "<<i+1<<": ";
		cin.getline(s,100);
		if(!checksonguyen(s)){
			cout<<"Nhap so nguyen\n";
		}
		else{
			x=chuyenkieu(s);
		}
	}
	while(!checksonguyen(s));
	Push(S,x);
	}
}

void Output(Stack S) //hien thi cac phan tu cua stack
{
	cout<<"Stack: ";
	for (int i=S.Top-1; i>=0; i--)
		cout<<S.Data[i]<<" ";
}

void themphantu(Stack &S, item &them, int &k){ //them phan tu vao vi tri bat ki
	if(Isfull(S)){ //kiem tra stack day hay chua?
		cout<<"Stack day, khong the chen";
	}
	else{
		char s[100];
		do{
			cout<<"Nhap gia tri can them: ";
			cin.getline(s,100);
			them=chuyenkieu(s);
			if(!checksonguyen(s)){
				cout<<"Nhap so nguyen!\n";
			}
		}
		while(!checksonguyen(s));
		Stack temp; //khai bao stack tam thoi
		Init(temp); //khoi tao
		int t=S.Top-k; //bien trung gian t de chuyen phan tu tu S sang temp
		while(t>=0){ 
		Push(temp,Pop(S)); //chuyen phan tu tu S sang temp
		t--;
		}
		Push(S,them); //them phan tu vao vi tri k
		while(temp.Top>0){
			Push(S,Pop(temp));  // lay lai gia tri ve S
		}
		cout<<"Da hoan thanh viec them phan tu!\n";
		Output(S); // hien thi S
	}	
}
void suaphantu(Stack &S, item &sua, int &vts){
	char s[100];
	do{
		cout<<"Nhap gia tri muon sua: ";
		cin.getline(s,100);
		sua=chuyenkieu(s);
		if(!checksonguyen(s)){
			cout<<"Nhap so nguyen!\n";
		}
	}
	while(!checksonguyen(s));
	Stack temp; //tao 1 stack tam
	Init(temp); //khoi tao no
	int m=S.Top-vts-1; //tao 1 bien trung gian de lay ra va sua cac phan tu cua stack
	while(m>=0){
		Push(temp,Pop(S)); //chuyen phan tu tu S sang temp
		m--;
	}
	Pop(S); //xoa bo phan tu tai vi tri can sua
	Push(S,sua); //them phan tu moi vao
	while(temp.Top>0){
		Push(S,Pop(temp)); // lay lai cac gia tri con lai ve S
	}
	cout<<"Da hoan thanh viec sua phan tu!\n";
	Output(S); // hien thi S
}
void xoaphantu(Stack &S, int &vt){
		if(Isempty(S)){ // kiem tra S rong hay khong?
			cout<<"\nStack rong, khong the xoa";
		}
		else{
			Stack tmp; //khai bao stack tam thoi
			Init(tmp); // khoi tao 
			int xoa=S.Top-vt;// bien xoa de lay phan tu tu S vao tmp
			while(xoa>0){
				Push(tmp,Pop(S)); // chuyen phan tu tu S sang tmp
				xoa--;
			}
			Pop(S); // xoa bo phan tu tai vi tri can xoa
			while(tmp.Top>0){
				Push(S,Pop(tmp)); // lay lai phan tu vao S
			}
			cout<<"Da hoan thanh viec xoa phan tu!\n";
			Output(S); //hien thi S
		}
}
//heta
//b
int checksonguyen(char *b){
	if(b[0]=='-'){
		int i=1;
		while(b[i]!=0){
			if('0'>b[i]||b[i]>'9') //kiem tra tung ki tu cua char, neu <'0' hoac >'9' tra ve false
			return 0;
			i++;
		}
		return 1;
	}
	else{
		int j=0;
		while(b[j]!=0){
			if('0'>b[j]||b[j]>'9') //kiem tra tung ki tu cua char, neu <'0' hoac >'9' tra ve false
			return 0;
			j++;
		}
		return 1;
	}
}
int chuyenkieu(char *s) //ham chuyen tu kieu char ve int
{
	int res = 0;
	if(s[0]=='-'){
		int res2=1;
			for(int i = 1; i < strlen(s); i++ )
			{
				res = res*10 + s[i]-48; //he thap phan, 1(int) ung voi 49(char)
			}
			res2 = res*(-1);
			return res2;
	}
	else{
		for(int i = 0; i < strlen(s); i++ )
		{
			res = res*10 + s[i]-48; //he thap phan, 1(int) ung voi 49(char)
		}
		return res;
	}
}

void Nhap (int *p, int n){
	char s[100];
	for(int i=0;i<n;i++){
	do{
		cout<<"a["<<i+1<<"] = ";
		cin.getline(s,100);
		if(!checksonguyen(s)){
			cout<<"Nhap so nguyen\n";
		}
		else{
			*(p+i)=chuyenkieu(s);
		}
	}
	while(!checksonguyen(s));
	}
}

void Xuat (int *p, int n){
	cout << "Mang: ";
	for ( int i = 0; i < n; i++)
		cout << *(p+i) << " ";
}

	bool ktcp(int &cp){ //kiem tra so chinh phuong?
		int sqr;
		sqr=sqrt(cp);
		if(sqr*sqr==cp&&cp!=0){
			return true;
		}
		else{
			return false;
		}
	}
	bool kthh(int &hh){ //kiem tra so hoan hao?
    	int sum = 0;
    	if(hh<1)
    		return false;
    	for(int i=1;i<=hh/2;i++){
       		if(hh%i==0) 
            	sum+=i;
    	}
    	if(sum==hh) return true;
    	return false;
	}
	bool ktnt(int &nt){ //kiem tra so nguyen to?
    	if (nt<=1){
     	   return false;
 	   }       
    	for(int i=2; i<nt; i++){
        	if (nt % i == 0){
           		return false;
        	}   
    	}
    	return true;
	}

void inracp(int *p, int n){
	int kt=0;//bien kiem trakhoi gan = 0 
	for(int i=0;i<n;i++){
		if(ktcp(*(p+i))){
			kt++; //neu ktcp dung thi tang bien kt
		}
	}
	if(kt==0){ //sau 1 vong lap, bien kt van =0 thi co nghia khong co so chinh phuong nao
		cout<<"\nKhong co so chinh phuong";
	}
	else{
		cout<<"\nSo chinh phuong: ";
		for(int i=0;i<n;i++){
			if(ktcp(*(p+i))){
				cout<<*(p+i)<<" ";// in ra cac so cp xuat hien
			}
		}
	}
}
void inrahh(int *p, int n){
	int kt=0;//khoi gan bien kt=0
	for(int i=0;i<n;i++){
		if(kthh(*(p+i))){
			kt++; //neu co so hh xuat hien, tang bien kt
		}
	}
	if(kt==0){ //bien kt khong thay doi, hien thi khong co so hoan hao
		cout<<"\nKhong co so hoan hao";
	}
	else{
		cout<<"\nSo hoan hao: ";
		for(int i=0;i<n;i++){
			if(kthh(*(p+i))){
				cout<<*(p+i)<<" "; //in ra cac so hh xuat hien
			}
		}
	}
}
void inrant(int *p, int n){
	int kt=0; //khoi gan bien kt=0
	for(int i=0;i<n;i++){
		if(ktnt(*(p+i))){
			kt++; //neu xuat hien snt, tang bien kt len
		}
	}
	if(kt==0){ //neu bien kt van =0, hien thi khong co so nguyen to
		cout<<"\nKhong co so nguyen to";
	}
	else{
		cout<<"\nSo nguyen to: ";
		for(int i=0;i<n;i++){
			if(ktnt(*(p+i))){
				cout<<*(p+i)<<" ";//in ra cac so nguyen to xuat hien
			}
		}
	}
}
//hetb

//e
void nhapmang(int &hang, int &cot, int A[100][100]) //nhap du lieu mang 2 chieu
{
	char s[100];
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			do{
				cout<<"A["<<i+1<<"]["<<j+1<<"] = ";
				cin.getline(s,100);
				if(!checksonguyen(s)){
					cout<<"Nhap so nguyen\n";
				}
				else{
					A[i][j]=chuyenkieu(s);
					//j++;
				}
			}
			while(!checksonguyen(s));
		}
	}
}

void xuatmang(int hang, int cot,int A[100][100]){
	cout<<"Mang la:\n";
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void interchangehang(int hang , int cot, int A[100][100]){
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot-1;j++){
			for(int k=j+1;k<cot;k++){
				if(A[i][j]>A[i][k]){ //doi cho 2 phan tu dung canh nhau trong 1 hang theo thu tu tang dan
					int tmp=A[i][j];
					A[i][j]=A[i][k];
					A[i][k]=tmp;
				}
			}
		}
	}
	cout<<"Mang sau sap xep interchange theo hang chieu tang dan:\n";
	xuatmang(hang,cot,A);
}

void interchangecot(int hang , int cot, int A[100][100]){
	for(int j=0;j<cot;j++){
		for(int i=0;i<hang-1;i++){
			for(int k=i+1;k<hang;k++){
				if(A[i][j]<A[k][j]){ //doi cho 2 phan tu dung canh nhau trong 1 cot theo thu tu giam dan
					int tmp=A[i][j];
					A[i][j]=A[k][j];
					A[k][j]=tmp;
				}
			}
		}
	}
	cout<<"Mang sau sap xep interchange theo cot chieu giam dan: \n";
	xuatmang(hang,cot,A);
}
void bubblesorthang(int hang, int cot, int A[100][100]){
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot-1;j++){
			for(int k=0;k<cot-j-1;k++){
				if(A[i][k]<A[i][k+1]){ //doi cho 2 phan tu dung canh nhau trong 1 hang theo thu tu giam dan
					int tmp=A[i][k];
					A[i][k]=A[i][k+1];
					A[i][k+1]=tmp;
				}
			}
		}
	}
	cout<<"Mang sau sap xep bubble sort theo hang chieu giam dan:\n";
	xuatmang(hang,cot,A);
}
void bubblesortcot(int hang, int cot, int A[100][100]){
	for(int j=0;j<cot;j++){
		for(int i=0;i<hang-1;i++){
			for(int k=0;k<hang-i-1;k++){
				if(A[k][j]>A[k+1][j]){ //doi cho 2 phan tu dung canh nhau trong 1 cot theo thu tu tang dan
					int tmp=A[k][j];
					A[k][j]=A[k+1][j];
					A[k+1][j]=tmp;
				}
			}
		}
	}
	cout<<"Mang sau sap xep bubble sort theo cot chieu tang dan:\n";
	xuatmang(hang,cot,A);
}
//hete

void duongcheochinh(int hang, int cot, int A[100][100]){
	if(hang!=cot){
		cout<<"Khong ton tai duong cheo chinh\n";//ma tran khong vuong thi khong co duong cheo chinh
	}
	else{
		cout<<"Duong cheo chinh: ";
		for(int i=0;i<hang;i++){
			cout<<A[i][i]<<" ";
		}
		cout<<"\n";
	}
}
void findminmax(int hang, int cot, int A[100][100]){
	int min=A[0][0];//khoi gan max bang phan tu dau tien
	int max=A[0][0];//khoi gan min bang phan tu dau tien
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(A[i][j]<min){
				min=A[i][j];
			}
			if(A[i][j]>max){
				max=A[i][j];
			}
		}
	}
	cout<<"Max la: "<<max;
	cout<<"\nMin la: "<<min;
}
void phantugiua(int hang, int cot, int A[100][100]){
	if(hang!=cot || hang%2==0){ // neu so hang la chan va ma tran khong vuong thi khong ton tai pt chinh giua 
		cout<<"\nKhong ton tai phan tu chinh giua";
	}
	else{
		cout<<"\nPhan tu chinh giua mang la: ";
		cout<<A[(hang-1)/2][(hang-1)/2];//hien thi phan tu chinh giua 	
	}
}
//

void sontmax(int *p, int n){
	//tao mang chi gom cac so nguyen to khac nhau
	int *b= new int [n];
	int *snt_max=b;
	int x=1;
	int kt=0;
	for(int i=0;i<n;i++){
		if(ktnt(*(p+i))){
			*(snt_max)=*(p+i);
			kt++;//gan phan tu dau tien chinh bang so nguyen to dau tien xuat hien trong mang ban dau
			break; //ket thuc luon vong lap khi gan thanh cong
		}
	}
	if(kt==0){
		cout<<"\nKhong co so nguyen to trong mang\n";
	}
	else{
	for(int i=1;i<n;i++){
		int dem1=1;//tao cac bien dem de kiem tra
		int dem2=0;
		for(int j=0;j<x;j++){
			if(ktnt(*(p+i))){
				dem1=0;//neu la snt thi dem1=0
			}
			if(*(p+i)==*(snt_max+j)){
				dem2++;//neu xuat hien tu 2 lan thi tang bien dem2
			}
		}
		if(dem1==0&&dem2==0){ //neu phan tu la so nguyen to thi cho vao mang snt_max voi xuat hien chi 1 lan
			*(snt_max+x)=*(p+i);
			x++;//tang bien x de tiep tuc gan vao mang
		}
	}
	//tao mang chua so lan xuat hien cua moi phan tu khong trung nhau
	int c[x];  
	for(int i=0;i<x;i++){
		//khoi gan cac gia tri xuat hien ban dau la 0
		c[i]=0;
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<n;j++){
			//neu trung nhau thi tang gia tri len 1
			if(*(p+j)==*(snt_max+i)){
				c[i]++;
			}
		}
	}
	//tim so lan xuat hien nhieu nhat
        //bien max luu so lan xuat hien nhieu nhat
        //bien id de luu dia chi cua so xuat hien nhieu nhat
    //bien y dung de dem so lan xuat hien bang nhau
    int max=c[0];
    int id=0;
    int y=1;
    //tim so lan xuat hien nhieu nhat va vi tri cua no
        for(int i=1;i<x;i++){
        if(c[i]>max){
            max=c[i];//tim max trong mang c(mang so lan xuat hien)
            id=i;//luu dia chi
            y=1; //xuat hien 1 lan
        }
        if(c[i]==max){ //neu c[i]==max thi tang so lan xuat hien len 1 dvi
            y++;
        }       
    }
     
    //neu chi co mot phan tu xuat hien nhieu nhat
    if(y==1){
        cout<<"\nPhan tu la so nguyen to xuat hien nhieu nhat la: "<<*(snt_max+id);
        cout<<", xuat hien "<<max<<" lan"<<endl;
    }
     
    //neu co tu hai phan tu xuat hien nhieu nhat
    else{
        int d[y]; //mang dung luu vi tri cua phan tu xuat hien nhieu nhat
        int z=0;//dung bien z de lam so luong phan tu mang d
        for(int i=0;i<x;i++)
            if(c[i]==max){//lay vi tri cua phan tu xuat hien nhieu nhat va luu vao mang d
                d[z]=i;
                z++;//tang bien z len de tiep tuc gan
            }
        //in ket qua ra man hinh
        cout<<"\nPhan tu la so nguyen to xuat hien nhieu nhat la: ";
        for(int i=0;i<z;i++ )
        {
        	if(ktnt(*(snt_max+d[i])));
        	cout<<*(snt_max+d[i])<<" ";
		}
            
        cout<<", xuat hien "<<max<<" lan\n"; 
    }
	}
}
struct DATE{ //dinh dang cau truc cua ngay thang
	int thang;
	double luongmuatb;
	float nhietdotb;	
};
	DATE dst[11];
void vaodulieu(DATE dst[11]){
	for(int i=0;i<12;i++){
		dst[i].thang=i+1;
	}
	//gan gia tri luong mua va nhiet do trung binh cac thang cua ha noi
	//thong so trung binh cua cac thang Ha Noi trong nhieu nam qua
	dst[0].luongmuatb=18.6;
	dst[0].nhietdotb=16.4;
	dst[1].luongmuatb=26.2;
	dst[1].nhietdotb=17;
	dst[2].luongmuatb=43.8;
	dst[2].nhietdotb=20.2;
	dst[3].luongmuatb=90.1;
	dst[3].nhietdotb=23.7;
	dst[4].luongmuatb=188.5;
	dst[4].nhietdotb=27.3;
	dst[5].luongmuatb=239.9;
	dst[5].nhietdotb=28.8;
	dst[6].luongmuatb=288.2;
	dst[6].nhietdotb=28.9;
	dst[7].luongmuatb=318;
	dst[7].nhietdotb=28.2;
	dst[8].luongmuatb=265.4;
	dst[8].nhietdotb=27.2;
	dst[9].luongmuatb=130.7;
	dst[9].nhietdotb=24.6;
	dst[10].luongmuatb=43.4;
	dst[10].nhietdotb=21.4;
	dst[11].luongmuatb=23.4;
	dst[11].nhietdotb=18.2;
}

void findthang(DATE dst[11], int thang){ //tim kiem thang theo yeu cau
	char s[100];
	do{
		cout<<"Nhap thang ban muon tim kiem: ";
		cin.getline(s,100);
		thang=chuyenkieu(s);
		if(!checksonguyen(s) || thang<0 || thang>12){
			cout<<"Khong hop le, nhap dung so thang!\n";
		}
	}
	while(!checksonguyen(s) || thang<0 || thang>12);
	for(int i=0;i<12;i++){
		if(thang-1==dst[i].thang){
			if(thang==2){
				cout<<"Thang "<<thang<<" co 28 ngay ";
			}
			else if(thang==4 || thang==6  || thang==9 || thang==11){
				cout<<"Thang "<<thang<<" co 30 ngay ";
			}
			else{
					cout<<"Thang "<<thang<<" co 31 ngay ";
			}
			if(thang<4){
				cout<<"\nThang "<<thang<<" la mua xuan";
			}
			else if(thang>3&&thang<7){
				cout<<"\nThang "<<thang<<" la mua ha";
			}
			else if(thang>6&&thang<10){
				cout<<"\nThang "<<thang<<" la mua thu";
			}
			else{
				cout<<"\nThang "<<thang<<" la mua dong";
			}
			cout<<"\nThang "<<thang<<" o Ha Noi co nhiet do trung binh la "<<dst[i].nhietdotb<<" (do C)";
			cout<<"\nCo luong mua trung binh la "<<dst[i].luongmuatb<<" (mm) "<<"<thong so tuong doi>";
			break;
		}
	}
	cout<<"\nCac thang co 30 ngay la: 4, 6, 9, 11";
}
void findsnt(int hang, int cot, int A[100][100]){ //tim scp xuat hien trong mang 2 chieu
	int kt=0;//tao bien kt kiem tra xem co so chinh phuong xuat hien hay khong?
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(ktnt(A[i][j])){
				kt++;
			}
		}
	}
	if(kt==0){
		cout<<"Khong co so nguyen to";
	}
	else{
		cout<<"Ket qua tim kiem: ";
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++){
				if(ktnt(A[i][j])){
					cout<<A[i][j]<<" ";
				}
			}
		}
	}
}
void findshh(int hang, int cot, int A[100][100]){ //tim scp xuat hien trong mang 2 chieu
	int kt=0;//tao bien kt kiem tra xem co so chinh phuong xuat hien hay khong?
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(kthh(A[i][j])){
				kt++;
			}
		}
	}
	if(kt==0){
		cout<<"Khong co so hoan hao";
	}
	else{
		cout<<"Ket qua tim kiem: ";
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++){
				if(kthh(A[i][j])){
					cout<<A[i][j]<<" ";
				}
			}
		}
	}
}
void findscp(int hang, int cot, int A[100][100]){ //tim scp xuat hien trong mang 2 chieu
	int kt=0;//tao bien kt kiem tra xem co so chinh phuong xuat hien hay khong?
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(ktcp(A[i][j])){
				kt++;
			}
		}
	}
	if(kt==0){
		cout<<"Khong co so chinh phuong";
	}
	else{
		cout<<"Ket qua tim kiem: ";
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++){
				if(ktcp(A[i][j])){
					cout<<A[i][j]<<" ";
				}
			}
		}
	}
}
int main()
{
	start:
	int control;
	char s[100];
	cout<<"                                         +---------------MENU----------------+\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      1.QUAN LY STACK              +\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      2.TIM SO MANG MOT CHIEU      +\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      3.DATE, KIEM TRA THANG       +\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      4.TIM SO MANG HAI CHIEU      +\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      5.SAP XEP MANG HAI CHIEU     +\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      6.XU LY MANG HAI CHIEU       +\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      7.TIM SO NGUYEN TO           +\n";
	cout<<"                                         +-----------------------------------+\n";
	cout<<"                                         +      0.THOAT                      +\n";
	cout<<"                                         +-----------------------------------+\n";
	do{
		cout<<"\nNhap Menu Ban Muon Thuc Hien: ";
		cin.getline(s,100);
		control=chuyenkieu(s);
		if(!checksonguyen(s) || control<0 || control>7){
			cout<<"Vui Long Chon Dung Menu!";
		}
	}
	while(!checksonguyen(s) || control<0 || control>7);
	switch(control){
		case 1:{
			system("cls");
			char s7[100];
			int select;
			Stack S;
			item them;
			item sua;
			int vts;
			int k;
			int vt;
    		Init(S);
    		Input(S);
    		Output(S);
			restart2:
			cout<<"\n                                         +-----------------MENU--------------+\n";
			cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +                1.THEM             +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +                2.XOA              +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +                3.SUA              +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +                0.QUAY LAI         +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		do{
				cout<<"Nhap Menu Muon Chon: ";
				cin.getline(s7,100);
				select=chuyenkieu(s7);
				if(!checksonguyen(s7) || select>3 || select<0){
					cout<<"Vui Long Nhap Dung Menu!\n";
				}
			}
			while(!checksonguyen(s7) || select>3 || select < 0);
			switch(select){
				case 1:{
					system("cls");
					Output(S);
					char s[100];
					do{
						cout<<"\nNhap vi tri can them: ";
						cin.getline(s,100);
						k=chuyenkieu(s);
						if(k<1 || k>S.Top || !checksonguyen(s)){
							cout<<"Nhap gia tri hop le!";
						}
					}
					while(!checksonguyen(s) || k<1 || k>S.Top);
    				themphantu(S,them,k);
    				cout<<"\nNhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					Output(S);
    				goto restart2;
					break;
				}
				case 2:{
					system("cls");
					Output(S);
					char s2[100];
    				do{
						cout<<"\nNhap vi tri can xoa: ";
						cin.getline(s2,100);
						vt=chuyenkieu(s2);
						if(vt<1 || vt>S.Top || !checksonguyen(s2)){
							cout<<"Nhap gia tri hop le!";
						}
					}
					while(!checksonguyen(s2) || vt<1 || vt>S.Top);
    				xoaphantu(S,vt);
    				cout<<"\nNhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					Output(S);
    				goto restart2;
					break;
				}
				case 3:{
					system("cls");
					Output(S);
					char s[100];
					do{
						cout<<"\nNhap vi tri can sua: ";
						cin.getline(s,100);
						vts=chuyenkieu(s);
						if(vts<1 || vts>S.Top || !checksonguyen(s)){
							cout<<"Nhap gia tri hop le!";
						}
					}
					while(!checksonguyen(s) || vts<1 || vts>S.Top);
					suaphantu(S,sua,vts);
					cout<<"\nNhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					Output(S);
					goto restart2;
					break;
				}
				case 0:{
					system("cls");
					break;
				}
			}
			break;
		}
		case 2:{
			system("cls");
			int n;
			char s[100];
			do{
				cout<<"Nhap so luong phan tu mang mot chieu: ";
				cin.getline(s,100);
				n=chuyenkieu(s);
				if(!checksonguyen(s) || n<1){
					cout<<"Nhap so nguyen duong!\n";
				}
			}
			while(!checksonguyen(s) || n<1);
			int *a = new int [n]; 
			int *p = a;
			Nhap(p,n);
			Xuat(p,n);
			inracp(p,n);
			inrahh(p,n);
			inrant(p,n);
			delete []a; 
			cout<<"\nNhan Phim Enter De Quay Lai!";
			fflush(stdin);
			getchar();
			fflush(stdin);
			system("cls");
			break;
		}
		case 3:{
			system("cls");
			DATE dst[11];
			int thang;
			vaodulieu(dst);
			findthang(dst,thang);
			cout<<"\nNhan Phim Enter De Quay Lai!";
			fflush(stdin);
			getchar();
			fflush(stdin);
			system("cls");
			break;
		}
		case 4:{
			system("cls");
			int hang,cot;
			int A[100][100];
			char s[100];
			do{
				cout<<"Nhap so hang: ";
				cin.getline(s,100);
				hang=chuyenkieu(s);
				if(!checksonguyen(s) || hang<1){
					cout<<"Nhap so nguyen duong!\n";
				}
			}
			while(!checksonguyen(s) || hang<1);
			char s3[100];
			do{
				cout<<"Nhap so cot: ";
				cin.getline(s3,100);
				cot=chuyenkieu(s3);
				if(!checksonguyen(s3) || cot<=hang){
					cout<<"Nhap so nguyen duong!(cot>hang)\n";
				}
			}
			while(!checksonguyen(s3) || cot<=hang);
			nhapmang(hang,cot,A);
			xuatmang(hang,cot,A);
			int chon;
			char s5[100];
			restart3:
			cout<<"\n                                         +----------------MENU---------------+\n";
			cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +           1.TIM MIN, MAX          +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +           2.TIM SO NGUYEN TO      +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +           3.TIM SO HOAN HAO       +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +           4.TIM SO CHINH PHUONG   +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		cout<<"                                         +           0.QUAY LAI              +\n";
    		cout<<"                                         +-----------------------------------+\n";
    		do{
				cout<<"Nhap Menu Muon Chon: ";
				cin.getline(s5,100);
				chon=chuyenkieu(s5);
				if(!checksonguyen(s5) || chon>4 || chon<0){
					cout<<"Vui long nhap dung menu!\n";
				}
			}
			while(!checksonguyen(s5) || chon>4 || chon<0);
			switch(chon){
				case 1:{
					system("cls");
					xuatmang(hang,cot,A);
					findminmax(hang,cot,A);
					cout<<"\nNhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart3;
					break;
				}
				case 2:{
					system("cls");
					xuatmang(hang,cot,A);
					findsnt(hang,cot,A);
					cout<<"\nNhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart3;
					break;
				}
				case 3:{
					system("cls");
					xuatmang(hang,cot,A);
					findshh(hang,cot,A);
					cout<<"\nNhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart3;
					break;
				}
				case 4:{
					system("cls");
					xuatmang(hang,cot,A);
					findscp(hang,cot,A);
					cout<<"\nNhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart3;
					break;
				}
				case 0:{
					system("cls");
					break;
				}
			}
			break;
		}
		case 5:{
			system("cls");
			int hang,cot;
			int A[100][100];
			char s[100];
			do{
				cout<<"Nhap so hang: ";
				cin.getline(s,100);
				hang=chuyenkieu(s);
				if(!checksonguyen(s) || hang<1){
					cout<<"Nhap so nguyen duong!\n";
				}
			}
			while(!checksonguyen(s) || hang<1);
			char s4[100];
			do{
				cout<<"Nhap so cot: ";
				cin.getline(s4,100);
				cot=chuyenkieu(s4);
				if(!checksonguyen(s4) || cot<1){
					cout<<"Nhap so nguyen duong!\n";
				}
			}
			while(!checksonguyen(s4) || cot<1);
			nhapmang(hang,cot,A);
			xuatmang(hang,cot,A);
			int chon;
			char s5[100];
			restart4:
			cout<<"\n                                         +----------------MENU-----------------+\n";
			cout<<"                                         +-------------------------------------+\n";
    		cout<<"                                         +      1.SAP XEP TANG DAN THEO COT    +\n";
    		cout<<"                                         +-------------------------------------+\n";
    		cout<<"                                         +      2.SAP XEP GIAM DAN THEO COT    +\n";
    		cout<<"                                         +-------------------------------------+\n";
    		cout<<"                                         +      3.SAP XEP TANG DAN THEO HANG   +\n";
    		cout<<"                                         +-------------------------------------+\n";
    		cout<<"                                         +      4.SAP XEP GIAM DAN THEO HANG   +\n";
    		cout<<"                                         +-------------------------------------+\n";
    		cout<<"                                         +      0.QUAY LAI                     +\n";
    		cout<<"                                         +-------------------------------------+\n";
    		do{
				cout<<"Nhap Menu Muon Chon: ";
				cin.getline(s5,100);
				chon=chuyenkieu(s5);
				if(!checksonguyen(s5) || chon>4 || chon<0){
					cout<<"Vui long nhap dung menu!\n";
				}
			}
			while(!checksonguyen(s5) || chon>4 || chon<0);
			switch(chon){
				case 1:{
					system("cls");
					bubblesortcot(hang,cot,A);
					cout<<"Nhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart4;
					break;
				}
				case 2:{
					system("cls");
					interchangecot(hang,cot,A);
					cout<<"Nhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart4;
					break;
				}
				case 3:{
					system("cls");
					interchangehang(hang,cot,A);
					cout<<"Nhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart4;
					break;
				}
				case 4:{
					system("cls");
					bubblesorthang(hang,cot,A);
					cout<<"Nhan Phim Enter De Quay Lai!";
					fflush(stdin);
					getchar();
					fflush(stdin);
					system("cls");
					xuatmang(hang,cot,A);
					goto restart4;
					break;
				}
				case 0:{
					system("cls");
					break;
				}
			}
			break;
		}
		case 6:{
			system("cls");
			int hang,cot;
			int A[100][100];
			do{
				cout<<"Nhap so hang: ";
				cin.getline(s,100);
				hang=chuyenkieu(s);
				if(!checksonguyen(s) || hang<1){
					cout<<"Nhap so nguyen duong!\n";
				}
			}
			while(!checksonguyen(s) || hang<1);
			char s4[100];
			do{
				cout<<"Nhap so cot: ";
				cin.getline(s4,100);
				cot=chuyenkieu(s4);
				if(!checksonguyen(s4) || cot<1){
					cout<<"Nhap so nguyen duong!\n";
				}
			}
			while(!checksonguyen(s4) || cot<1);
			nhapmang(hang,cot,A);
			xuatmang(hang,cot,A);
			duongcheochinh(hang,cot,A);
			findminmax(hang,cot,A);
			phantugiua(hang,cot,A);
			cout<<"\nNhan Phim Enter De Quay Lai!";
			fflush(stdin);
			getchar();
			fflush(stdin);
			system("cls");
			break;
		}
		case 7:{
			system("cls");
			int n;
			int *snt_max;
			char s[100];
			do{
				cout<<"Nhap so luong phan tu mang mot chieu: ";
				cin.getline(s,100);
				n=chuyenkieu(s);
				if(!checksonguyen(s) || n<1){
					cout<<"Nhap so nguyen duong!\n";
				}
			}
			while(!checksonguyen(s) || n<1);
			int *a = new int [n]; 
			int *p = a;
			Nhap(p,n);
			Xuat(p,n);
			sontmax(p,n);
			delete [] a;
			cout<<"Nhan Phim Enter De Quay Lai!";
			fflush(stdin);
			getchar();
			fflush(stdin);
			system("cls");
			break;
		}
		case 0:{
			exit(0);
			break;
		}
	}
	goto start;
}
