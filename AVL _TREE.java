package AVLassign;
import java.util.*;

class TreeNode
{
	TreeNode lc,rc;
	String name;
	String telephone;
	int h;
	public TreeNode(String n,String t)   //parameterized constructor of class node
	{
		name=n;
		telephone=t; 
		lc=rc=null;
		h=0;
	}
}
class AVL
{
	private TreeNode root;   
	public AVL()
	{
		root=null;
	}
	
	int height(TreeNode troot)   // height to calculate balance factor of tree
	{
		if(troot==null) {
			return 0;
			}
		else {
			int l=height(troot.lc);
			int r=height(troot.rc);
			if(l>r) {
				return l+1;
				}
			else {
				return r+1;
				}
			}
	}
	
	int balanceFactor(TreeNode troot)   
	{
		 if (troot == null)
		       return 0;
		   return height(troot.lc) - height(troot.rc);
		
	}
	
	TreeNode LL(TreeNode parent)   
	{
		TreeNode ptr = parent.rc;
		parent.lc=ptr.rc;
		ptr.rc=parent;
		ptr.h=height(ptr);
		return ptr;
		
	}
	
	TreeNode RR(TreeNode parent)    
	{
		TreeNode ptr=parent.rc;
		parent.rc=ptr.lc;
		ptr.lc=parent;
		ptr.h=height(ptr);
		return ptr;
	}
	
	TreeNode LR(TreeNode root)
	{
		
		root.lc=RR(root.lc);
		root=LL(root);
		return root;
	}
	
	TreeNode RL(TreeNode root)    
	{
		root.rc=LL(root.rc);
		root=RR(root);
		return root;
	}
	
	 TreeNode insert(TreeNode troot,TreeNode temp)
	{
		 /* 1.  Perform the normal BST insertion */
	        if (troot == null)
	            return temp;
	 
	        if (temp.name.compareTo(troot.name)<0)
	            troot.lc = insert(troot.lc,temp);
	        else if (temp.name.compareTo(troot.name)>0)
	            troot.rc = insert(troot.rc,temp);
	        else
	            return troot;
	        troot.h = height(troot);
	 
	       
	        int balance = balanceFactor(troot);
	 
	        if (balance > 1 && temp.name.compareTo(troot.lc.name)<0)
	            return RR(troot);
	 
	        if (balance < -1 &&  temp.name.compareTo(troot.rc.name)>0)
	            return LL(troot);
	 
	        // Left Right Case
	        if (balance > 1 &&  temp.name.compareTo(troot.lc.name)>0) 
	        	return LR(troot);
	        
	        // Right Left Case
	        if (balance < -1 &&  temp.name.compareTo(troot.rc.name)<0) 
	        	return RL(troot);
	        return troot;
	}
	public void create()    //Accept general information from customer
	{
		Scanner sn=new Scanner(System.in);
		int ch;
		
		do {
			Scanner scan=new Scanner(System.in);
			String name, telephone;
			System.out.println("Enter the name:");
			name=scan.next();
			System.out.println("Enter the telephone number:");
			telephone=scan.next();
			TreeNode temp=new TreeNode(name,telephone);
			root=insert(root,temp);
			System.out.println("Do you want to continue(1 for yes/0 for No): ");
			ch=sn.nextInt();
		}while(ch!=0);
		
		
	}
	public void display()           // Inorder  traversal 
	{
		inOrder(root);
	}
	private void inOrder(TreeNode root) 
	{
		 if (root!= null) {
             inOrder(root.lc);
            System.out.println("name:"+root.name + "  phone no:"+root.telephone);
            inOrder(root.rc);
        }
	}
}


public class MainClass {
	public static void main(String[] args) {
		AVL avl=new AVL();
		Scanner scan=new Scanner(System.in);
		int ch;
		do
		{
			System.out.println("\n*********************");
			System.out.println("MENU:\n1.ACCEPT\n2.DISPLAY\n0.EXIT");
			System.out.println("*********************");
			System.out.println("Enter your choice:");
			ch=scan.nextInt();
			switch(ch)
			{
			case 1:
				avl.create();
				break;
				
			case 2:
				avl.display();
				break;
			}
		}while(ch!=0);

	}
}
/*import java.util.*;

class node
{
	node lc,rc;
	String name;
	String telephone;
	int h;
	public node(String n,String t)   //parameterized constructor of class node
	{
		name=n;
		telephone=t; 
		lc=rc=null;
		h=0;
	}
}

class AVL
{
	private node root;   
	public AVL()
	{
		root=null;
	}
	
	int height(node root)   // height to calculate balance factor of tree
	{
		
	}
	
	int balanceFactor(node root)   
	{
		
	}
	
node LL(node ptr)   
	{
		
	}
	
	node RR(node ptr)    
	{
		
	}
	
	node LR(node root)
	{
		root.lc=RR(root.lc);
		root=LL(root);
		return root;
	}
	
	node RL(node root)    
	{
		root.rc=LL(root.rc);
		root=RR(root);
		
		return root;
	}
	
	 node insert(node root,node temp)
	{
		
	}
	
	public void create()    //Accept general information form customer
	{
		Scanner scan=new Scanner(System.in);
		String name, telephone;
		System.out.println("Enter the name:");
		name=scan.next();
		System.out.println("Enter the telephone number:");
		telephone=scan.next();
		node temp=new node(name,telephone);
		root=insert(root,temp);
		
		
	}
	public void display()           // Inorder  traversal 
	{
		
	}
}

public class Main{

	public static void main(String[] args) {
		AVL avl=new AVL();
		Scanner scan=new Scanner(System.in);
		int ch;
		do
		{
			System.out.println("\n*********************");
			System.out.println("MENU:\n1.ACCEPT\n2.DISPLAY\n0.EXIT");
			System.out.println("*********************");
			System.out.println("Enter your choice:");
			ch=scan.nextInt();
			switch(ch)
			{
			case 1:
				avl.create();
				break;
				
			case 2:
				avl.display();
				break;
			}
		}while(ch!=0);

	}

}

*/