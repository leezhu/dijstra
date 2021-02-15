#include<iostream>
#include<time.h>
#include<vector>
#include <fstream>
#include<string>
#include<algorithm>
using namespace std;
#define N 10
#define MAXN 100
//sequence metrix
int worK_sequence[10][10] = { { 3, 1, 2, 4, 6, 5, 7, 8, 9, 10 },
{ 2, 3, 5, 6, 7, 8, 1, 4, 10, 9 },
{ 3, 4, 7, 8, 2, 5, 6, 10, 9, 1 },
{ 7, 8, 2, 1, 3, 4, 10, 9, 5, 6 },
{ 3, 7, 8, 2, 5, 10, 9, 6, 1, 4 },
{ 2, 4, 7, 9, 10, 6, 8, 1, 5, 3 },
{ 5, 6, 3, 10, 9, 4, 7, 8, 2, 1 },
{ 4, 9, 10, 6, 3, 5, 1, 2, 8, 7 },
{ 5, 10, 9, 6, 4, 1, 2, 3, 7, 8 },
{ 6, 2, 1, 5, 8, 3, 4, 7, 10, 9 } };
//each sequnece working-time
int work_time[10][10] = { { 5, 20, 25, 35, 15, 35, 30, 35, 35, 20 },
{ 40, 30, 50, 40, 45, 20, 30, 15, 30, 35 },
{ 20, 20, 40, 45, 5, 40, 15, 35, 50, 10 },
{ 30, 30, 25, 25, 40, 50, 35, 15, 35, 50 },
{ 40, 15, 30, 20, 5, 5, 35, 35, 35, 30, },
{ 10, 10, 40, 50, 20, 10, 35, 40, 35, 30 },
{ 35, 30, 35, 30, 10, 45, 45, 15, 15, 45 },
{ 20, 30, 50, 20, 20, 35, 30, 50, 20, 30 },
{ 10, 35, 20, 30, 30, 30, 45, 30, 45, 50 },
{ 40, 10, 30, 35, 40, 15, 35, 20, 40, 20 } };

const int work_piece = N;
const int device = N;
const int population = 5;
const int generation = 100;
const int mutation_pro = 0.1;//mutation probability
const int cross_pro = 0.5;	//cross probability

//��ά�����Ⱦɫ��
int chrom[population][N][N];




//ÿ��Ⱦɫ��������ʱ��
int fastCompleTime[5];

//���ŵ����ʱ��,�����ŵ�Ⱦɫ��
int bestMachineSequence[N][N];
int bestChrom[N][N];
int bestIndex;
int best_time = 9999;

//����Ⱦɫ����
int worstChromIndex;

ofstream myfout("result.txt", ios::trunc);


//transform the sequence to adapt from 0
void transform_sequence()
{
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			worK_sequence[i][j] = worK_sequence[i][j] - 1;
}

//swap
void myswap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//void swap
//����ı�����
void changeSequence(int chrom[N][N])
{

	//for (int ix = 0; ix < N;ix++)
	//{
	int n = 100;
	//����10��
	while (n--)
	{

		int pos_1 = rand() % 99;
		int pos_2 = rand() % 99;

		///cout << "pos1=: " << pos_1 << " " << "pos_2: " << pos_2 << endl;
		myswap(chrom[pos_1 / 10][pos_1 % 10], chrom[pos_2 / 10][pos_2 % 10]);

	}


	//}
}
//intial population
void initial_population()
{

	srand(time(NULL));//ʱ�����Ӳ��ܷ���ѭ������
	transform_sequence();
	memset(fastCompleTime, 0, sizeof(fastCompleTime));//��ʼ��������ʱ��
	for (int ix = 0; ix < population; ix++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{

				chrom[ix][i][j] = j;

			}
		}
	}
	for (int ix = 0; ix < population; ix++)
	{
		changeSequence(chrom[ix]);
	}

	//for (int i = 2; i < 4; i++)
	//{
	//	cout << i << "-------------------------" << endl;
	//	for (int ix = 0; ix < N; ix++)
	//	{
	//		for (int iy = 0; iy < N; iy++)
	//		{
	//		cout << chrom[i][ix][iy] << " ";
	//		}
	//	//cout << endl;
	//	}
	//	cout << endl;
	//}

}

void caculate_time()
{

	int machinePos[N];
	int sequenceAdd[N];
	int machineTime[N][N];
	int jobPos[N][N];
	//��ʼ��



	//cout<< " Workpiece   machineNum   machinePos[machineNum] "<< endl;
	//���ҹ���,���»���ʱ���

	for (int pop = 0; pop < population; pop++)
	{
		memset(machineTime, 0, sizeof(machineTime));
		memset(machinePos, 0, sizeof(machinePos));
		memset(sequenceAdd, 0, sizeof(sequenceAdd));
		memset(jobPos, 0, sizeof(jobPos));
		for (int ix = 0; ix < N; ix++)
		{
			for (int iy = 0; iy < N; iy++)
			{
				int pos = chrom[pop][ix][iy];
				//	cout << pos;
				int machineNum = worK_sequence[pos][sequenceAdd[pos]];


				//cout << machineNum<<" ";
				//�жϻ����ϸ����������ʱ��͹����ϸ���������ʱ���С



				if (0 == machinePos[machineNum])
				{
					if (0 == sequenceAdd[pos])
					{
						machineTime[machineNum][machinePos[machineNum]] = work_time[pos][sequenceAdd[pos]];//˵���ǻ����ĵ�һ�������������ĵ�һ������
					}
					else
					{
						int wokrPieceFrontNum = worK_sequence[pos][sequenceAdd[pos] - 1];
						//machinepos�Ѿ�++��������Ҫ�ҳ�����һ��������ʱ�䣬���в���

						int index = 0;
						for (int i = 0; i < machinePos[machineNum];i++)
						{
							if (jobPos[machineNum][i]==wokrPieceFrontNum)
							{
								index = i;
								break;
							}
						}

						machineTime[machineNum][machinePos[machineNum]] = work_time[pos][sequenceAdd[pos]] +
							machineTime[wokrPieceFrontNum][index];//˵���ǻ����ĵ�һ���������ǹ����ĵ�һ������
					}
				}
				else if (0 == sequenceAdd[pos] && (0 != machinePos[machineNum]))
				{
					machineTime[machineNum][machinePos[machineNum]] = work_time[pos][sequenceAdd[pos]] +
						machineTime[machineNum][machinePos[machineNum] - 1];//˵���ǹ����ĵ�һ������ֻҪ��ӻ�����ǰһ�����������
				}
				else
				{
					int temp1 = machineTime[machineNum][machinePos[machineNum] - 1];//��������һ������
					int wokrPieceFrontNum = worK_sequence[pos][sequenceAdd[pos] - 1];
					int temp2 = machineTime[wokrPieceFrontNum][machinePos[wokrPieceFrontNum]];//��������һ������

					if (temp1 > temp2)//�������һ���������ʱ��ȹ�����һ���������ʱ��С
					{
						machineTime[machineNum][machinePos[machineNum]] = work_time[pos][sequenceAdd[pos]] +
							machineTime[machineNum][machinePos[machineNum] - 1];
					}
					else
						machineTime[machineNum][machinePos[machineNum]] = work_time[pos][sequenceAdd[pos]] +
						machineTime[wokrPieceFrontNum][machinePos[wokrPieceFrontNum]];
					// m++;

				}
				jobPos[machineNum][machinePos[machineNum]] = pos;
				sequenceAdd[pos] = sequenceAdd[pos] +1 ;
				machinePos[machineNum] = machinePos[machineNum] +1 ;
				//cout << "job"<<pos << machineNum << "            " << machinePos[machineNum] << endl;



			}
			//cout << endl;
		}

		/*cout << "---------------------------------" << endl;
		for (int ix = 0; ix < N; ix++)
		{
		for (int iy = 0; iy < N; iy++)
		{
		cout << "job" << jobPos[ix][iy] << " " << machineTime[ix][iy] << " ";
		}
		cout << endl;
		}*/


		//����������ʱ�䡣
		for (int ix = 0; ix < N; ix++)
		{
			if (machineTime[ix][9]>fastCompleTime[pop])
			{
				fastCompleTime[pop] = machineTime[ix][9];
			}
		}

		//��¼һ�������ŵĻ�����������
		if (fastCompleTime[pop]<best_time)
		{
			best_time = fastCompleTime[pop];
			bestIndex = pop;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					bestMachineSequence[i][j] = jobPos[i][j];
					bestChrom[i][j] = chrom[pop][i][j];
				}
			}
		}


		

	}

	//��ӡ������ʱ��
	/*for (int ix = 0; ix < population; ix++)
	{
		cout << " fastCompleTime=" << fastCompleTime[ix] << " \n";
	}*/
	//cout << "m=: " << m;
	/*for (int ix = 0; ix < N; ix++)
	{
	for (int iy = 0; iy < N; iy++)
	{
	cout << machineTime[ix][iy] << " ";
	}
	cout << endl;
	}
	*/
}

//only mutation,����λ�ñ���
void mutation_population()
{
	srand(time(NULL));

	double mutPro = rand() % 1000 / 1000.0;
	if (mutPro>mutation_pro)
	{
		for (int ix = 0; ix < population; ix++)
		{
			changeSequence(chrom[ix]);
		}
	}
	

}

//���򲻱�㽻��
void cross_population()
{

	srand(time(NULL));
	int k = population;
	int child[N][N];
	memset(child, 0, sizeof(child));

	//�����Ⱦɫ���������������
	while (k--)
	{
		//ѡȡ��������
		//���ݽ������������ѡ��
		double pro = rand() % 1000 / 1000.0;
		if (pro>cross_pro)
		{
			int fathercrossPos = rand() % (population - 1);//Ⱦɫ����������λ��
			int montercrossPos = rand() % (population - 1);
			while (fathercrossPos == montercrossPos)
			{
				montercrossPos = rand() % (population - 1);
			}

			//ѡ���򲻱�㣬Ȼ����ĸϵȾɫ��ĳ��������Ľ��в�ȫ

			int chromCrossPos = rand() % (N - 1);
			int m = 0;
			int n = 0;

			while (m < 100)
			{
				if (chrom[montercrossPos][m / N][m%N] == chromCrossPos)
				{
					m++;
					continue;
				}
				else if (chrom[fathercrossPos][n / N][n%N] == chromCrossPos)
				{
					n++;
					continue;
				}


				chrom[fathercrossPos][n / N][n%N] = chrom[montercrossPos][m / N][m%N];
				m++;
				n++;

			}

		}
		
		//cout << "changg==============" << endl;
		//for (int i = 0; i < N;i++)
		//{
		//	for (int j = 0; j < N;j++)
		//	{
		//		cout << chrom[2][i][j] << " ";
		//	}
		//	//cout << endl;
		//}

		//}


	}

}

//�õ����Ž����С���ʱ�䣬���޳�����Ⱦɫ��
void updateBest()
{



	//�������̶ģ�������޳�

	double chromPro[population];//ÿ��Ⱦɫ���Ŀ��ֵ���������ۼ�
	int sum = 0;				//�ܵ�Ŀ��ֵ
	int chromHit[population];	//ÿ��Ⱦɫ�����еĴ���

	memset(chromPro, 0.0, sizeof(chromPro));
	memset(chromHit, 0, sizeof(chromHit));

	for (int i = 0; i < N; i++)
	{
		sum += fastCompleTime[i];
	}

	chromPro[0] = fastCompleTime[0]*1.0 / sum;

	for (int i = 1; i < N; i++)
	{
		chromPro[i] = chromPro[i - 1] + fastCompleTime[i]*1.0/sum;
	}

	double pro = rand() % 1000 / 1000.0;

	//���̶�
	if (pro<chromPro[0])
	{
		chromHit[0]++;
	}
	else if (pro<chromPro[1])
	{
		chromHit[1]++;
	}
	else if (pro<chromPro[2])
	{
		chromHit[2]++;
	}
	else if (pro<chromPro[3])
	{
		chromHit[3]++;
	}
	else
	{
		chromHit[4]++;
	}


	//�ҳ���С��
	int min = 99;
	int minIndex;
	for (int i = 0; i < 5;i++)
	{
		if (chromHit[i]<min)
		{
			min = chromHit[i];
			minIndex = i;
		}
	}
	
	//�����ŵ����滻����

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N;j++)
		{
			chrom[minIndex][i][j] = bestChrom[i][j];
		}
	}
	
}


void evolution()
{

	mutation_population();
	cross_population();
	caculate_time();
	updateBest();



}

int main()
{
	int generation = 0;

	initial_population();
	caculate_time();

	while (generation < 100)
	{
		generation++;
		evolution();
		myfout << "The " << generation << " generation:" << endl;
		myfout << "the Min Operation time is:" << best_time << endl;
		for (int i = 0; i < N; i++)
		{
			myfout << "Machine " << i + 1 << ": ";
			for (int j = 0; j < N; j++)
				myfout <<"Job_"<< bestMachineSequence[i][j]+1 << " / ";
			myfout << endl;
		}

	}
	system("pause");
	
	return 0;
}