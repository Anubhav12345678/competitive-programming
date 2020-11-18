//reverse a stack in O(1) space
void insert(stack<int> &s,int ele)
{
	if(s.empty())
		s.push(ele);
	else{
		int tmp = s.top();
		s.pop();
		insert(s,ele);
		s.push(tmp);
	}
}

void reverse(stack<int> &s)
{
	if(s.size()<=1) return;
	int tmp = s.top();
	s.pop();
	reverse(s);
	insert(tmp);
}

// del middle element of stack in O(1) space mid ele is k=(st.size())/2 + 1;
stack<int> midDel(stakc<int> &st){
	if(st.empty())
		return st;
	int k = (st.size()/2)+1;
	solve(st,k);
	return st;
}

void solve(stack<int> &st,int k)
{
	if(k==1){
		st.pop();
		return st;
	}

	int tmp = st.top();
	st.pop();
	solve(st,k-1);
	st.push(tmp); 
}

//sort a stack using recursion

void insert(stack<int> &st,int x)
{
   if(st.empty()||st.top()>=x)
   	st.push(x);
   else
   {
   	 int tmp = st.top();
   	 st.pop();
   	 insert(st,x);
   	 st.push(tmp);
   }
}
void sort(stack<int> &st)
{
	if(st.size()<=1) return;
	int tmp = st.top();
	st.pop();
	sort(st);
	insert(st,tmp);
}