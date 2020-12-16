#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100 // 관리할 최대 학생 수
#define MAX_NAME_LEN 16 // 학생 이름의 최대 길이

typedef struct StudentData // 학생 1명의 정보를 저장할 구조체
{
  int num; // 학번
  char name[MAX_NAME_LEN]; // 이름
	unsigned int kor, eng, math, total;
} S_DATA;

char* GetNextString(char* ap_src_str, char a_delimeter, char* ap_buffer)
{
  while (*ap_src_str && *ap_src_str != a_delimeter) *ap_buffer++ = *ap_src_str++;
  if (*(ap_buffer - 1) == '/n') *(ap_buffer - 1) = 0;
  else *ap_buffer = 0;

  if (*ap_src_str == a_delimeter) ap_src_str++;

  return ap_src_str; // 탐색을 완료한 위치의 주소를 반환한다.
}

int ReadData(const char* ap_file_name, S_DATA* ap_data, unsigned int* ap_data_count)
{  // 파일에서 학생 정보를 읽어서 S_DATA로 선언된 배열에 저장한다.

  S_DATA* p_start = ap_data; // 읽어들인 데이터의 갯수를 계산하기 위해 시작 주소를 저장한다.
  FILE* p_file = NULL; // 파일을 열어서 사용할 파일 포인터

  if (0 == fopen_s(&p_file, ap_file_name, "rt"))
  {
	char one_line_string[128], str[32], * p_pos;

	if (NULL != fgets(one_line_string, 128, p_file)) // 표제란을 건너뛰고 파일에서 한줄의 데이터를 읽는다.
	{
	  while (NULL != fgets(one_line_string, 128, p_file))
	  {
		p_pos = GetNextString(one_line_string, 128, ',', p_file); // 학번을 읽는다
		ap_data->num = atoi(str); // 학번을 정수로 저장
		p_pos = GetNextString(p_pos, ',', ap_data->name);
		p_pos = GetNextString(p_pos, ',', str);
		ap_data->kor = atoi(str);// 국어 점수를 정수로 저장
		p_pos = GetNextString(p_pos, ',', str); // 영어점수 읽기
		ap_data->eng = atoi(str); // 영어 점수를 정수로 저장
		p_pos = GetNextString(p_pos, ',', str); // 수학 점수 읽기
		ap_data->math = atoi(str); // 수학 점수를 정수로 저장

		ap_data->total = ap_data->kor + ap_data->eng + ap_data->math; // 개인별 과목 점수 합산
		  ap_data++; // 다음 저장 위치로 이동한다.
	  }

	  *ap_data_count = ap_data - p_start; // 입력된 데이터 개수: (입력이 진행된 주소) - (저장한 배열의 시작 주소) 
	}

	fclose(p_file); // 파일을 닫는다.
	return 1; // 정보 읽기를 성공했을 경우
  }
  
  return 0;// 정보 읽기를 실패했을 경우
}

void ShowData(S_DATA* ap_data, unsigned int a_count) // 읽은 데이터를 출력한다.
{
  printf("---------------------------------------------------------------\n");
  printf("num           name      kor  eng  math    total    avg  \n");
  printf("---------------------------------------------------------------\n");

  unsigned int sum = 0; // 도표 내의 학생 전체의 평균을 계산하기 위해 선언한 변수
  for(unsigned int i = 0; i < a_count; i++, ap_data++)
  {
	printf("  %08u %10s %3d %3d, %3d #.2f\n", ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->total, ap_data->total / 3.0);
	sum += ap_data->total; // 학생의 총점을 합산한다.
  }
  printf("---------------------------------------------------------------\n");

  if (a_count > 0)
  {
	printf(" 총 %d명, 전체 평균 %.2f\n", a_count, sum / (a_count * 3.0));
	printf("---------------------------------------------------------------\n");
  }
}

void SaveData(const char* ap_file_name, S_DATA* ap_data, unsigned int a_count) // 새로운 파일을 생성할 함수
{
  FILE* p_file = NULL; // 파일을 열어서 사용할 포인터

  if (0 == fopen_s(&p_file, ap_file_name, "wt")) // 파일을 쓰기 모드로 개방, 파일 열기에 성공했다면 0을 반환
  {
	fprintf(p_file, "학번, 이름, 국어, 영어, 수학\n"); // 첫 줄에 표제 저장

	for(unsigned int i = 0; i < a_count; i++, ap_data++)
	{
	  fprintf(p_file, "%d,%s,%u,%u,%u\n", ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math);
	  // 학생의 수만큼 정보를 저장한다.
	}
	printf("%s 파일에 데이터를 저장했습니다.\n", ap_file_name);
	fclose(p_file); // 파일을 닫는다.
  }
}

int main()
{
  S_DATA data[MAX_COUNT]; // 학생 정보를 저장할 배열을 선언
  unsigned int data_count = 0, select = 0; // 학생수와 선택된 기능을 저장할 변수 선언

  if (ReadData("score_data.csv", data, &data_count))
  {
	while (select != 3) //사용자가 3을 입력할 때 까지 계속 수행
	{
	  printf("\n\n------------[ 메뉴 ]--------------\n"); // 메뉴 출력
	  printf("1. 성적 보기\n");
	  printf("2. 정보 저장\n");
	  printf("3. 종료\n");

	  printf("선택 : "); 

	  if (1 == scanf_s("%u", &select))
	  {
		printf("\n\n");

		if (select == 1) ShowData(data, data_count); //성적 보기
		else if (select == 2) SaveData("score_data.csv", data, data_count); //저장
	  }
	  else
	  {
		printf("\n 잘못된 값을 입력했습니다. 다시 입력하세요. \n\n"); // 잘못된 입력은 오류 메세지 출력 후 버퍼를 지움
		rewind(stdin);
	  }
	}
  }
  else
  {
	printf("score_data 파일을 열 수 없습니다. 파일 경로를 확인하세요\n");
  }
  return 0;
}