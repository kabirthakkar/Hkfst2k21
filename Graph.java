

package assign3;

import java.util.*;

class Graph
{
	int n; //number of vertices
	int e; //number of edges
	int[][] adjMat; //adjacency matrix of the graph
    LinkedList<Integer> adj[];//adjacency List of the graph
	
	Graph()//Default Constructor
	{
		n = 0;
		e = 0;
	}
	void createUsingAdjMat()//Accepting Undirected Graph
	{
		Scanner sc=new Scanner(System.in);
	
		System.out.println("Enter no of houses: ");
		n=sc.nextInt();//Accept  number of Houses
		System.out.println("Enter no of lanes: ");
		e=sc.nextInt();//Accept number of Lanes
		adjMat=new int[n][n];
		for(int k=0;k<n;k++) {
			for(int j=0;j<n;j++) {
				adjMat[k][j]=0;
			}
		}
		for(int i=0;i<e;i++)//For every lane
		{
			System.out.println("Enter the two end points: ");
			int a=sc.nextInt();
			int b=sc.nextInt();
			adjMat[a][b]=1;
			adjMat[b][a]=1;
		}		
	}
	
	void displayAdjMat()	//Displaying Adjacency Matrix	
	{
		System.out.print(" ");
		for(int i=0;i<n;i++)
			System.out.print(i + " ");
		System.out.println(" ");
		for(int i=0;i<n;i++) {
			System.out.print(i + " ");
			for(int j=0;j<n;j++) {
				System.out.print( adjMat[i][j] + " ");
			}
			System.out.println(" ");
		}
	}
	void addEdge(int v,int w)//Function to add edge in adjacency list
        {
       		 adj[v].add(w);
        }

	void createUsingAdjList()	//For directed graph
	{
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter no of houses: ");
		n=sc.nextInt();//Accept  number of Houses
		adj = new LinkedList[n];
        for (int i=0; i<n; ++i)
            adj[i] = new LinkedList();
		System.out.println("Enter no of lanes: ");
		e=sc.nextInt();//Accept number of Lanes
		for(int i=0;i<e;i++) {
			System.out.println("Enter the two end points: ");
			int a=sc.nextInt();
			int b=sc.nextInt();
			addEdge(a,b);
			
				
			}
	}
	
	
		
	void displayAdjList()	//Displaying adjacency list
	{
		    for (int i = 0; i < n; i++) {
		      System.out.print("\nVertex " + i + ":");
		      Iterator<Integer> it = adj[i].listIterator();
		      while(it.hasNext()) {
		    	  int n=it.next();
		        System.out.print(" -> " + n);
		      }
		      System.out.println();
		    }
		  
		
	}
	
	void bfs()//Breadth first traversal for adjacency list
	{
		System.out.println("The BFS TRAVERSAL IS: ");
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the starting vertex: ");
		int s=sc.nextInt();//Accepting source
		 boolean visited[] = new boolean[n];
		 
	        // Create a queue for BFS
	        LinkedList<Integer> queue = new LinkedList<Integer>();
	 
	        // Mark the current node as visited and enqueue it
	        visited[s]=true;
	        queue.add(s);
	 
	        while (queue.size() != 0)
	        {
	            // Dequeue a vertex from queue and print it
	            s = queue.poll();
	            System.out.print(s+" ");
	 
	            // Get all adjacent vertices of the dequeued vertex s
	            // If a adjacent has not been visited, then mark it
	            // visited and enqueue it
	            Iterator<Integer> i = adj[s].listIterator();
	            while (i.hasNext())
	            {
	                int n = i.next();
	                if (!visited[n])
	                {
	                    visited[n] = true;
	                    queue.add(n);
	                }
	            }
	        }	
	   }
	
	
	void dfs() {//Depth first search for adjacency matrix
		System.out.println("The DFS TRAVERSAL IS: ");
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the starting vertex: ");
		int s=sc.nextInt();//Accepting source
		boolean[] visited = new boolean[adjMat.length];
		DFS(s,visited);//Recursive function call
	}
	void DFS(int start, boolean[] visited)//recursive implementation of DFS
		{
		  
		    // Print the current node
		    System.out.print( start + " ");
		  
		    // Set current node as visited
		    visited[start] = true;
		  
		    // For every node of the graph
		    for (int i = 0; i < n; i++) {
		  
		        // If some node is adjacent to the current node
		        // and it has not already been visited
		        if (adjMat[start][i] == 1 && (!visited[i])) {
		            DFS(i, visited);//Recursive call
		        }
		    }
	}


}


public class MainClass//main class
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Graph g = new Graph();
		int ch;

		do
		{
			System.out.println("\n\tChoose any 1 option");//MENU
			System.out.println("\n\t1.Adjacency Matrix");
			System.out.println("\n\t2.Adjacency List");
			System.out.println("\n\t3.Exit");
			ch = sc.nextInt();

			switch(ch)
			{
				case 1://For undirected graph
				
				g.createUsingAdjMat();
				g.displayAdjMat();
				g.dfs();
				
				break;

				case 2://for directed graph
				
				g.createUsingAdjList();
				g.displayAdjList();
				g.bfs();
				break;

				case 3:
				System.exit(0);
			}

		}while(ch != 3);		
		
	}
}

/*TIME COMPLEXITIES
 * createUsingAdjList = O(e)
 * displayAdjList = O(e)
 * createUsingAdjMat = O(n^2)
 * displayAdjMat = O(n^2)
 * BFS= O(n+e)....used adjacency List
 * DFS= O(n^2)...used adjacency matrix
 * 
 * 
 * 
 * 
 * INPUTS:
 * UNDIRECTED GRAPH:
 * 
 *          
 *  1       3
 *   \     /
 *    \   /
 *      0
 *     /  \
 *    /    \
 *   2      4
 *   
 *   
 *   DIRECTED GRAPH
 *   
 *   
 *   0----->1
 *  /|\    /
 *   |    /       ------
 *   |   /        |    |
 *  \|/|/_-------->3<---
 *   2
 *   
 *   UNCONNECTED UNDIRECTED GRAPH:
 * 
 *          
 *  1       3
 *   \     /
 *    \   /
 *      0
 *     /  
 *    /  
 *   2      4
 *  
 *   UNCONNECTED  DIRECTED GRAPH
 *   
 *   
 *   0----->1
 *  /|\    /
 *   |    /       ------
 *   |   /        |    |
 *  \|/|/_        3<---
 *   2
 *   
    Output:
    
	Choose any 1 option

	1.Adjacency Matrix

	2.Adjacency List

	3.Exit
1
Enter no of houses: 
5
Enter no of lanes: 
4
Enter the two end points: 
0
1
Enter the two end points: 
0
2
Enter the two end points: 
0
3
Enter the two end points: 
0
4
 0 1 2 3 4  
0 0 1 1 1 1  
1 1 0 0 0 0  
2 1 0 0 0 0  
3 1 0 0 0 0  
4 1 0 0 0 0  
The DFS TRAVERSAL IS: 
Enter the starting vertex: 
0
0 1 2 3 4 
	Choose any 1 option

	1.Adjacency Matrix

	2.Adjacency List

	3.Exit
2
Enter no of houses: 
4
Enter no of lanes: 
6
Enter the two end points: 
0
2
Enter the two end points: 
2
0
Enter the two end points: 
0
1
Enter the two end points: 
1
2
Enter the two end points: 
2
3
Enter the two end points: 
3
3

Vertex 0: -> 2 -> 1

Vertex 1: -> 2

Vertex 2: -> 0 -> 3

Vertex 3: -> 3
The BFS TRAVERSAL IS: 
Enter the starting vertex: 
2
2 0 3 1 
	Choose any 1 option......UNCONNECTED GRAPHS

	1.Adjacency Matrix

	2.Adjacency List

	3.Exit
1
Enter no of houses: 
5
Enter no of lanes: 
3
Enter the two end points: 
0
1
Enter the two end points: 
0
2
Enter the two end points: 
0
3
 0 1 2 3 4  
0 0 1 1 1 0  
1 1 0 0 0 0  
2 1 0 0 0 0  
3 1 0 0 0 0  
4 0 0 0 0 0  
The DFS TRAVERSAL IS: 
Enter the starting vertex: 
0
0 1 2 3 
	Choose any 1 option...UNCONNECTED GRAPHS

	1.Adjacency Matrix

	2.Adjacency List

	3.Exit
2
Enter no of houses: 
4
Enter no of lanes: 
5
Enter the two end points: 
0
2
Enter the two end points: 
2
0
Enter the two end points: 
0
1
Enter the two end points: 
1
2
Enter the two end points: 
3
3

Vertex 0: -> 2 -> 1

Vertex 1: -> 2

Vertex 2: -> 0

Vertex 3: -> 3
The BFS TRAVERSAL IS: 
Enter the starting vertex: 
2
2 0 1 
	Choose any 1 option

	1.Adjacency Matrix

	2.Adjacency List

	3.Exit
3

*/