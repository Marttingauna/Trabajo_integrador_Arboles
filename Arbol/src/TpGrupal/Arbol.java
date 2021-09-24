package TpGrupal;

import java.util.Stack;
public class IterativePostOrderTraversal extends BinaryTree {
    public static void iterativePostOrderTraversal(Node root){
        Node cur = root;
        Node pre = root;
        Stack<Node> s = new Stack<Node>();
        if(root!=null) s.push(root);
        System.out.println("sysout"+s.isEmpty());
        while(!s.isEmpty()){
            cur = s.peek();
            if(cur==pre||cur==pre.left ||cur==pre.right){// we are traversing down the tree
                if(cur.left!=null){
                    s.push(cur.left);
                }
                else if(cur.right!=null){
                    s.push(cur.right);
                }
                if(cur.left==null && cur.right==null){
                    System.out.println(s.pop().data);
                }
            }else if(pre==cur.left){// we are traversing up the tree from the left
                if(cur.right!=null){
                    s.push(cur.right);
                }else if(cur.right==null){
                    System.out.println(s.pop().data);
                }
            }else if(pre==cur.right){// we are traversing up the tree from the right
                System.out.println(s.pop().data);
            }
            pre=cur;
        }
    }
    public static void main(String args[]){
        BinaryTree bt = new BinaryTree();
        Node root = bt.generateTree();
        iterativePostOrderTraversal(root);
    }
}