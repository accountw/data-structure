package cn.edu.cdu.zb.sqlist;

public class SqList {
	int maxsize=100;//˳�����󳤶�
	int[] elemtype;//����
	int length;//˳�����
	
	
	//����һ���յ�˳���
	public SqList() {
		this.elemtype = new int[maxsize];
		this.length = 0;
	}
	
	//����
	public boolean insert(int i,int e) {	
		if(i<1||i>length) {
			System.out.println("����λ�ô���");
			return false;
		}
		if(length>=maxsize) {
			System.out.println("λ������");
			
		}
		int j;
		for(j=length;j>=i;j--) {
			this.elemtype[j]=this.elemtype[j-1];
		}
		this.elemtype[i-1]=e;
		length++;
		return true;
	}
	
	//ɾ��
	public boolean delete(int i) {
		if(i<1||i>length) {
			System.out.println("ɾ��λ�ô���");
			return false;
		}
		int j;
		for(j=i;j<length;j++) {
			this.elemtype[j-1]=this.elemtype[j];
		}
		length--;
		return true;
	}
	
	//����
	public void list() {
		int i;
		for(i=0;i<length;i++) {
			System.out.println("��"+(i+1)+"��Ԫ����"+this.elemtype[i]);
		}
		
	}

}
