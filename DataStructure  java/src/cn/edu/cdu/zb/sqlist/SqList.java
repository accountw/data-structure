package cn.edu.cdu.zb.sqlist;

public class SqList {
	int maxsize=100;//顺序表最大长度
	int[] elemtype;//数组
	int length;//顺序表长度
	
	
	//构造一个空的顺序表
	public SqList() {
		this.elemtype = new int[maxsize];
		this.length = 0;
	}
	
	//插入
	public boolean insert(int i,int e) {	
		if(i<1||i>length) {
			System.out.println("插入位置错误");
			return false;
		}
		if(length>=maxsize) {
			System.out.println("位置已满");
			
		}
		int j;
		for(j=length;j>=i;j--) {
			this.elemtype[j]=this.elemtype[j-1];
		}
		this.elemtype[i-1]=e;
		length++;
		return true;
	}
	
	//删除
	public boolean delete(int i) {
		if(i<1||i>length) {
			System.out.println("删除位置错误");
			return false;
		}
		int j;
		for(j=i;j<length;j++) {
			this.elemtype[j-1]=this.elemtype[j];
		}
		length--;
		return true;
	}
	
	//遍历
	public void list() {
		int i;
		for(i=0;i<length;i++) {
			System.out.println("第"+(i+1)+"个元素是"+this.elemtype[i]);
		}
		
	}

}
