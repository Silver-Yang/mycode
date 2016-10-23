#include <vector>
#include <string>
#include <iostream>

void compute_prefix_function(const char *p, int length, std::vector<int> &pi)
{
	pi.resize(strlen(p));
	pi[0]=0;
	int match_num=0;
	for(int i=1;i<length;i++){
		while(match_num>0 && *(p+i)!=*(p+match_num)) 
			match_num=pi[match_num];
		if(*(p+i)==*(p+match_num))
			match_num++;
		pi[i]=match_num;
	}

	std::cout<<"string length:"<<length<<std::endl;
	for(int i=0;i<length;i++)
		std::cout<<"pi["<<i<<"]"<<" : "<<pi[i]<<std::endl;
}

void kmp_matcher(const char* text, const char* pattern)
{
	int t_length=strlen(text);
	int p_length=strlen(pattern);
	std::vector<int> pi;
	pi.resize(p_length);
	compute_prefix_function(pattern,p_length,pi);
	int match_num=-1;
	for(int i=0;i<t_length;i++)
	{
		while(match_num>0 && *(text+i)!=*(pattern+match_num+1))
			match_num=pi[match_num];
		if(*(text+i)==*(pattern+match_num+1))
			match_num++;
		if(match_num==p_length-1)
		{
			std::cout<<"Pattern occurs with shift:"<<i-match_num<<std::endl;
			match_num=pi[match_num];
		}
	}
}

void kmp_matcher1(const char* pattern, int length,std::vector<int> pi)
{
	int suffix=-1;
	pi[0]=-1;
	for(int i=1;i<length;){
		while(suffix>=0 && pattern[i]!=pattern[suffix])
			suffix=pattern[suffix];
		i++;suffix++;
		pi[i]=suffix;
	}
	std::cout<<"string length:"<<length<<std::endl;
	for(int i=0;i<length;i++)
		std::cout<<"pi["<<i<<"]"<<" : "<<pi[i]<<std::endl;
}
//int kmp_matcher(std::vector<char> pattern,std::vector<int> pi)
//{
//	int length=pattern.size();
//	pi[0]=-1;
//	int j=-1;
//	std::cout<<"string length:"<<length<<std::endl;
//	for(int i=1;i<length;){
//		while(j>=0 && pattern[i]!=pattern[j]){
//			j=pi[j];
//		}
//		j++;
//		i++;
//		pi[i]=j;
//	}
//	for(int i=0;i<length;i++)
//		std::cout<<"pi["<<i<<"]"<<" : "<<pi[i]<<std::endl;
//	return 0;
//}

int main()
{
	std::vector<int> pi;
	char s[]="ababababca";
	char s1[] = "abcdeabcdefgabcdabcdefg";
	char text[]="bacbababacabab";
	char pat[]="ababaa";

//	kmp_matcher(pattern,pi);
//	kmp_matcher1(s,strlen(s),pi);
//	compute_prefix_function(s,strlen(s),pi);
//	compute_prefix_function(s1,strlen(s1),pi);
	kmp_matcher(text,s1);

	return 0;
}
