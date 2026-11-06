#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct SinhVien{
	char masv[5];
	char hoten[50];
	float diem1;
    float diem2;
    float diem3;
}SinhVien;
void nhapDanhSach(SinhVien *ds, int n){
	for (int i = 0; i < n; i++){
		SinhVien *sv = ds + i;
		printf("Thong tin sinh vien thu %d\n", i + 1);
        printf("MSV: ");
        scanf("%19s", sv->masv);
        
        while (getchar() != '\n');

        printf("Ho va ten: ");
        fgets(sv->hoten, sizeof(sv->hoten), stdin);
        sv->hoten[strcspn(sv->hoten, "\n")] = '\0';

        printf("Diem mon 1: ");
        scanf("%f", &(sv->diem1));

        printf("Diem mon 2: ");
        scanf("%f", &(sv->diem2));

        printf("Diem mon 3: ");
        scanf("%f", &(sv->diem3));
	}
}
void inDanhSach(const SinhVien *ds, int n) {
    printf("%-5s %-15s %-25s %-10s %-10s %-10s %-10s\n", "STT", "MSV", "Ho ten", "Diem 1", "Diem 2", "Diem 3", "Diem TB");
    for (int i = 0; i < n; i++) {
        const SinhVien *sv = ds + i;
        float diemTB = (sv->diem1 + sv->diem2 + sv->diem3) / 3.0f;
        printf("%-5d %-15s %-25s %-10.2f %-10.2f %-10.2f %-10.2f\n",
               i + 1,
               sv->masv,
               sv->hoten,
               sv->diem1,
               sv->diem2,
               sv->diem3,
               diemTB);
    }
}
int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong khong hop le!\n");
        return 1;
    }
    SinhVien *ds = (SinhVien *)malloc(n * sizeof(SinhVien));
    if (ds == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
    nhapDanhSach(ds, n);
    inDanhSach(ds, n);

    free(ds);
    ds = NULL;

    return 0;
}
