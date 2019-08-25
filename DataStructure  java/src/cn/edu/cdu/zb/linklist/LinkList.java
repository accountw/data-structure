package cn.edu.cdu.zb.linklist;


public class LinkList{
	
	
	private Node head,tail;//����һ��ͷ����β���
	
	public LinkList() {
		head=tail=null;//��ʼ����ͷβ��㶼Ϊ��
	}
	
	//�ж������Ƿ�Ϊ��
	public boolean isEmpty(){
		return head==null;
	}
	
	//��ͷ����������
	public void addToHead(int e) {
		head=new Node(e,head);
		if(tail==null) {
			tail=head;
		}
	}
	
	//��β����������
	public void addToTail(int e) {
		if(!isEmpty()) {
			tail.next=new Node(e);
			tail=tail.next;
		}
		else {
			head=tail=new Node(e);
		}
		
	}
	
	//��ָ��λ���������
	public void add(int n,int e) {
		Node tmp=head;
		Node newNode=new Node(e);
		if(n==1) {
			head=newNode;
			head.next=tmp;
		}
		else {
		for(int i=1;i<n-1;i++) {
			if(tmp.next==null) {
				System.out.println("���λ�ò���");
				return;
			}else {
				tmp=tmp.next;
			}
		}
		newNode.next=tmp.next;
		tmp.next=newNode;
		
	}
	}
	
	//ɾ��ֵΪe�Ľ��
	public void delete(int e) {
		if(!isEmpty()) {
			if(head==tail && e==head.data) {
				head=tail=null;
			}else if (e==head.data) {
				head=head.next;
			}else {
				Node pred, tmp;
				for(pred=head,tmp=head.next;tmp!=null &&tmp.data!=e;pred=pred.next,tmp=tmp.next); 
					if(tmp!=null) {
						pred.next=tmp.next;
						if(tmp==tail) {
							tail=pred;
						}
					}
				
			}
		}
	}
	
	//����n������ֵ��Ϊe
	public void  change(int n,int e) {
		Node tmp=head;
		for(int i=1;i<n;i++) {
			tmp=tmp.next;
		}
		tmp.data=e;
	}
	
	
	
	//��ӡ��������
	public void printAll() {
		for(Node tmp=head;tmp!=null;tmp=tmp.next) {
			System.out.println(tmp.data);
		}
	}
}
