package cn.edu.cdu.zb.linklist;

//����һ���ڵ���
public class Node {
	public int data;
	public Node next;
	public Node (int i) {
		this(i,null);
		
	}
	public Node(int i,Node node) {
		data=i;
		next=node;
	}

}
