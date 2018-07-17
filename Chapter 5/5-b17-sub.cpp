/* 1班 1651574 贾昊霖 */
/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

int tj_strlen(const char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i; //return值可根据需要修改
}

int tj_strcat(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int s1_len = tj_strlen(s1), i;
	for (i = s1_len; s2[i - s1_len] != '\0'; i++)
		s1[i] = s2[i - s1_len];
	s1[i] = '\0';
	return 0; //return值可根据需要修改
}

int tj_strcpy(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int s2_len = tj_strlen(s2);
	for (int i = 0; i <= s2_len; i++)
		s1[i] = s2[i];
	//已包含尾0
	return 0; //return值可根据需要修改
}

int tj_strncpy(char s1[], const char s2[], const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int s2_len = tj_strlen(s2);
	for (int i = 0; i < len && i < s2_len; i++)
		s1[i] = s2[i];
	return 0; //return值可根据需要修改
}

int tj_strcmp(const char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int s1_len = tj_strlen(s1);
	int s2_len = tj_strlen(s2);
	int len_min = s1_len <= s2_len ? s1_len : s2_len;
	for (int i = 0; i <= len_min; i++) {
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return s1[i] - s2[i];
	}
	return 0; //return值可根据需要修改
}

int tj_strcasecmp(const char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int s1_len = tj_strlen(s1);
	int s2_len = tj_strlen(s2);
	int len_min = s1_len <= s2_len ? s1_len : s2_len;
	for (int i = 0; i <= len_min; i++) {
		char c1 = s1[i], c2 = s2[i];
		if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'A' && c2 <= 'Z'))
			c1 -= 32;
		else if ((c2 >= 'a' && c2 <= 'z') && (c1 >= 'A' && c1 <= 'Z'))
			c2 -= 32;
		if (c1 < c2 || c1 > c2)
			return c1 - c2;
	}
	return 0; //return值可根据需要修改
}

int tj_strncmp(const char s1[], const char s2[], const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int s1_len = tj_strlen(s1);
	int s2_len = tj_strlen(s2);
	int len_min = s1_len <= s2_len ? s1_len : s2_len;
	for (int i = 0; i < len && i <= len_min; i++) {
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return s1[i] - s2[i];
	}
	return 0; //return值可根据需要修改
}

int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int s1_len = tj_strlen(s1);
	int s2_len = tj_strlen(s2);
	int len_min = s1_len <= s2_len ? s1_len : s2_len;
	for (int i = 0; i < len && i <= len_min; i++) {
		char c1 = s1[i], c2 = s2[i];
		if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'A' && c2 <= 'Z'))
			c1 -= 32;
		else if ((c2 >= 'a' && c2 <= 'z') && (c1 >= 'A' && c1 <= 'Z'))
			c2 -= 32;
		if (c1 < c2 || c1 > c2)
			return c1 - c2;
	}
	return 0; //return值可根据需要修改
}

int tj_strupr(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = tj_strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return 0; //return值可根据需要修改
}

int tj_strlwr(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = tj_strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return 0; //return值可根据需要修改
}

int tj_strchr(const char str[], char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = tj_strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == ch)
			return i + 1;
	}
	return 0; //return值可根据需要修改
}
/*KMP algorithm*/
void SetNext1(const char substr[], int next[])
{
	int len = tj_strlen(substr);
	int pre = -1, cur = 0;
	next[0] = -1;
	while (cur < len - 1) {
		if (pre == -1 || substr[pre] == substr[cur])
			next[++cur] = ++pre;
		else
			pre = next[pre];
	}
}
/*optimal solution*/
void SetNext2(const char substr[], int next[])
{
	int len = tj_strlen(substr);
	int pre = -1, cur = 0;
	next[0] = -1;
	while (cur < len - 1) {
		if (pre == -1 || substr[pre] == substr[cur]) {
			pre++;
			cur++;
			/*if char is equal, matching must be a failure*/
			if (substr[pre] == substr[cur])
				next[cur] = next[pre];
			else
				next[cur] = pre;
		}
		else
			pre = next[pre];
	}
}
/*most intelligible solution*/
void SetNext3(const char substr[], int next[])
{
	int len = tj_strlen(substr);
	int pre = 0;
	next[0] = -1;
	next[1] = 0;
	for (int cur = 1; cur < len - 1; cur++) {
		while (pre != 0 && substr[pre] != substr[cur])
			pre = next[pre];
		if (substr[pre] == substr[cur])
			pre++;
		next[cur + 1] = pre;
	}
}
int KMP(const char str[], const char sub[])
{
	int p_str = 0, p_sub = 0;
	int len_str = tj_strlen(str), len_sub = tj_strlen(sub);
	int next[1000];//应该动态申请的..您不让...= =
	SetNext2(sub, next);
	while (p_str < len_str && p_sub < len_sub) {
		if (p_sub == -1 || str[p_str] == sub[p_sub]) {
			p_str++;
			p_sub++;
		}
		else
			p_sub = next[p_sub];
	}
	return (p_sub == len_sub) ? p_str - p_sub + 1 : 0;
}
int tj_strstr(const char str[], const char substr[])
{
	return KMP(str, substr); //return值可根据需要修改
}

int tj_strrchr(const char str[], const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = tj_strlen(str);
	for (int i = len; i >= 0; i--) {
		if (str[i] == ch)
			return i + 1;
	}
	return 0; //return值可根据需要修改
}

void SetNext_reverse(const char sub[], int next[])
{
	int len = tj_strlen(sub);
	int pre = len, cur = len - 1;
	next[len - 1] = len;
	while (cur > 0) {
		if (pre == len || sub[pre] == sub[cur]) {
			pre--;
			cur--;
			if (sub[pre] == sub[cur])
				next[cur] = next[pre];
			else
				next[cur] = pre;
		}
		else
			pre = next[pre];
	}
}
int KMP_reverse(const char str[], const char sub[])
{
	int len_str = tj_strlen(str), len_sub = tj_strlen(sub);
	int p_str = len_str - 1, p_sub = len_sub - 1;
	int next[1000];
	SetNext_reverse(sub, next);
	while (p_str >= 0 && p_sub >= 0) {
		if (p_sub == len_sub || str[p_str] == sub[p_sub]) {
			p_sub--;
			p_str--;
		}
		else
			p_sub = next[p_sub];
	}
	return (p_sub < 0) ? p_str - p_sub + 1 : 0;
}

int tj_strrstr(const char str[], const char substr[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	return KMP_reverse(str, substr); //return值可根据需要修改
}

int tj_strrev(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = tj_strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char tmp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = tmp;
	}
	return 0; //return值可根据需要修改
}
