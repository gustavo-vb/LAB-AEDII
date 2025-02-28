
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.util.LinkedList;
import java.util.Stack;
import javax.swing.*;

public class ClassesEstruturasDados extends JFrame
        implements ActionListener, WindowListener {

    JButton botao1, botao2;
    JTextField textbox;

    LinkedList lista;
    Stack pilha;
    String nome;

    public ClassesEstruturasDados() {
        System.out.println(botao1);

        setLayout(null);
        setBounds(300, 0, 640, 480);
        setTitle("Java");
        getContentPane().setBackground(Color.DARK_GRAY);

        textbox = new JTextField();
        textbox.setBounds(130, 350, 350, 30);
        botao1 = new JButton("Insere");
        botao1.setBounds(150, 400, 100, 25);
        botao1.addActionListener(this);
        botao2 = new JButton("Mostra");
        botao2.setBounds(350, 400, 100, 25);
        botao2.addActionListener(this);

        getContentPane().add(botao1);
        getContentPane().add(botao2);
        getContentPane().add(textbox);

        lista = new LinkedList();
        pilha = new Stack();
        addWindowListener(this);
        
        
    }

    public static void main(String argumentos[]) {
        JFrame janela = new ClassesEstruturasDados();
        janela.setVisible(true);

    }

    @Override
    public void actionPerformed(ActionEvent evento) {
        if (evento.getSource() == botao1)
        {
            nome = textbox.getText();
            
            if(!nome.isEmpty())
            {
                System.out.println("Inserindo <" + nome + "> na lista e na pilha");
                lista.add(nome);
                pilha.push(nome);
                textbox.setText("");
            } else
              {
                System.out.println("A caixa de texto esta vazia!");
              }
        }

        if (evento.getSource() == botao2) {
            if (!lista.isEmpty())
            {
                System.out.println("Primeiro na lista = " + lista.getFirst());
                System.out.println("Ultimo na lista = " + lista.getLast());            
                System.out.println("Mostrando a lista");
                for (int i = 0; i < lista.size(); i++) {
                    System.out.println(lista.get(i));
                }
            }
            else
                System.out.println("Lista vazia...");
        
            if (!pilha.empty())
            {
                System.out.println("Topo da pilha = " + pilha.peek());

                System.out.println("Mostrando a pilha da base para o topo");
                int i = 0;
                while (i < pilha.size()) {
                System.out.println(pilha.get(i));
                i++;
                }

                System.out.println("Mostrando a pilha do topo para a base");
                i = pilha.size() - 1;
                while (i >= 0) {
                    System.out.println(pilha.get(i));
                    i--;
                }
            }
            else
                System.out.println("Pilha vazia...");
        }
    }

    @Override
    public void windowOpened(WindowEvent we) {
    }

    @Override
    public void windowClosing(WindowEvent we) {
        this.dispose();
        System.exit(1);
    }

    @Override
    public void windowClosed(WindowEvent we) {
        this.dispose();
        System.exit(1);
    }

    @Override
    public void windowIconified(WindowEvent we) {
    }

    @Override
    public void windowDeiconified(WindowEvent we) {
    }

    @Override
    public void windowActivated(WindowEvent we) {
    }

    @Override
    public void windowDeactivated(WindowEvent we) {
    }
}
