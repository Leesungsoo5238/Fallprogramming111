#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100 // ������ �ִ� �л� ��
#define MAX_NAME_LEN 16 // �л� �̸��� �ִ� ����

typedef struct StudentData // �л� 1���� ������ ������ ����ü
{
  int num; // �й�
  char name[MAX_NAME_LEN]; // �̸�
	unsigned int kor, eng, math, total;
} S_DATA;

char* GetNextString(char* ap_src_str, char a_delimeter, char* ap_buffer)
{
  while (*ap_src_str && *ap_src_str != a_delimeter) *ap_buffer++ = *ap_src_str++;
  if (*(ap_buffer - 1) == '/n') *(ap_buffer - 1) = 0;
  else *ap_buffer = 0;

  if (*ap_src_str == a_delimeter) ap_src_str++;

  return ap_src_str; // Ž���� �Ϸ��� ��ġ�� �ּҸ� ��ȯ�Ѵ�.
}

int ReadData(const char* ap_file_name, S_DATA* ap_data, unsigned int* ap_data_count)
{  // ���Ͽ��� �л� ������ �о S_DATA�� ����� �迭�� �����Ѵ�.

  S_DATA* p_start = ap_data; // �о���� �������� ������ ����ϱ� ���� ���� �ּҸ� �����Ѵ�.
  FILE* p_file = NULL; // ������ ��� ����� ���� ������

  if (0 == fopen_s(&p_file, ap_file_name, "rt"))
  {
	char one_line_string[128], str[32], * p_pos;

	if (NULL != fgets(one_line_string, 128, p_file)) // ǥ������ �ǳʶٰ� ���Ͽ��� ������ �����͸� �д´�.
	{
	  while (NULL != fgets(one_line_string, 128, p_file))
	  {
		p_pos = GetNextString(one_line_string, 128, ',', p_file); // �й��� �д´�
		ap_data->num = atoi(str); // �й��� ������ ����
		p_pos = GetNextString(p_pos, ',', ap_data->name);
		p_pos = GetNextString(p_pos, ',', str);
		ap_data->kor = atoi(str);// ���� ������ ������ ����
		p_pos = GetNextString(p_pos, ',', str); // �������� �б�
		ap_data->eng = atoi(str); // ���� ������ ������ ����
		p_pos = GetNextString(p_pos, ',', str); // ���� ���� �б�
		ap_data->math = atoi(str); // ���� ������ ������ ����

		ap_data->total = ap_data->kor + ap_data->eng + ap_data->math; // ���κ� ���� ���� �ջ�
		  ap_data++; // ���� ���� ��ġ�� �̵��Ѵ�.
	  }

	  *ap_data_count = ap_data - p_start; // �Էµ� ������ ����: (�Է��� ����� �ּ�) - (������ �迭�� ���� �ּ�) 
	}

	fclose(p_file); // ������ �ݴ´�.
	return 1; // ���� �б⸦ �������� ���
  }
  
  return 0;// ���� �б⸦ �������� ���
}

void ShowData(S_DATA* ap_data, unsigned int a_count) // ���� �����͸� ����Ѵ�.
{
  printf("---------------------------------------------------------------\n");
  printf("num           name      kor  eng  math    total    avg  \n");
  printf("---------------------------------------------------------------\n");

  unsigned int sum = 0; // ��ǥ ���� �л� ��ü�� ����� ����ϱ� ���� ������ ����
  for(unsigned int i = 0; i < a_count; i++, ap_data++)
  {
	printf("  %08u %10s %3d %3d, %3d #.2f\n", ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->total, ap_data->total / 3.0);
	sum += ap_data->total; // �л��� ������ �ջ��Ѵ�.
  }
  printf("---------------------------------------------------------------\n");

  if (a_count > 0)
  {
	printf(" �� %d��, ��ü ��� %.2f\n", a_count, sum / (a_count * 3.0));
	printf("---------------------------------------------------------------\n");
  }
}

void SaveData(const char* ap_file_name, S_DATA* ap_data, unsigned int a_count) // ���ο� ������ ������ �Լ�
{
  FILE* p_file = NULL; // ������ ��� ����� ������

  if (0 == fopen_s(&p_file, ap_file_name, "wt")) // ������ ���� ���� ����, ���� ���⿡ �����ߴٸ� 0�� ��ȯ
  {
	fprintf(p_file, "�й�, �̸�, ����, ����, ����\n"); // ù �ٿ� ǥ�� ����

	for(unsigned int i = 0; i < a_count; i++, ap_data++)
	{
	  fprintf(p_file, "%d,%s,%u,%u,%u\n", ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math);
	  // �л��� ����ŭ ������ �����Ѵ�.
	}
	printf("%s ���Ͽ� �����͸� �����߽��ϴ�.\n", ap_file_name);
	fclose(p_file); // ������ �ݴ´�.
  }
}

int main()
{
  S_DATA data[MAX_COUNT]; // �л� ������ ������ �迭�� ����
  unsigned int data_count = 0, select = 0; // �л����� ���õ� ����� ������ ���� ����

  if (ReadData("score_data.csv", data, &data_count))
  {
	while (select != 3) //����ڰ� 3�� �Է��� �� ���� ��� ����
	{
	  printf("\n\n------------[ �޴� ]--------------\n"); // �޴� ���
	  printf("1. ���� ����\n");
	  printf("2. ���� ����\n");
	  printf("3. ����\n");

	  printf("���� : "); 

	  if (1 == scanf_s("%u", &select))
	  {
		printf("\n\n");

		if (select == 1) ShowData(data, data_count); //���� ����
		else if (select == 2) SaveData("score_data.csv", data, data_count); //����
	  }
	  else
	  {
		printf("\n �߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��ϼ���. \n\n"); // �߸��� �Է��� ���� �޼��� ��� �� ���۸� ����
		rewind(stdin);
	  }
	}
  }
  else
  {
	printf("score_data ������ �� �� �����ϴ�. ���� ��θ� Ȯ���ϼ���\n");
  }
  return 0;
}