
// void *DoStuff(void *t)
// {
// 	pthread_mutex_lock(&mutex1);

// 	long t_id;
// 	t_id = ((long)t + 1);

// 	for (int i = ((t_id - 1) * ARR_SIZE); i < (t_id * ARR_SIZE - 1); i++)
// 	{
// 		Arr_Sum[i] = Arr_A[i] + Arr_B[i];
// 		Add_Sum += Arr_Sum[i];

// 		Arr_Sub[i] = Arr_A[i] - Arr_B[i];
// 		Sub_Sum += Arr_Sub[i];

// 		// Arr_Mul[i] = Arr_A[i] * Arr_B[i];
// 		Mul_Sum += Arr_A[i] * Arr_B[i];;

// 		Arr_Div[i] = (double)Arr_A[i] / (double)Arr_B[i];
// 		Div_Sum += Arr_Div[i];
// 	}

// 		pthread_mutex_unlock(&mutex1);
// }