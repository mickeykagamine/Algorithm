package oo6;

import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionAdapter;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Vector;
import java.util.concurrent.CopyOnWriteArrayList;

import javax.swing.BorderFactory;
import javax.swing.JCheckBox;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JTextArea;
import javax.swing.SwingConstants;

class gv {// ���ù���
	public static int MAXNUM = 1000000;

	public static long getTime() {// ��õ�ǰϵͳʱ��
		// Requires:��
		// Modifies:��
		// Effects:����long���͵��Ժ���Ƶ�ϵͳʱ��
		return System.currentTimeMillis();
	}

	@SuppressWarnings("static-access")
	public static void stay(long time) {
		// Requires:long���͵��Ժ���Ƶ�����ʱ��
		// Modifies:��
		// Effects:ʹ��ǰ�߳�����time��ʱ��
		try {
			Thread.currentThread().sleep(time);
		} catch (InterruptedException e) {

		}
	}

	public static void printTime() {
		// Requires:��
		// Modifies:System.out
		// Effects:����Ļ�ϴ�ӡHH:mm:ss:SSS��ʽ�ĵ�ǰʱ��
		SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss:SSS");
		System.out.println(sdf.format(new Date(getTime())));
	}

	public static String getFormatTime() {
		// Requires:��
		// Modifies:��
		// Effects:����String���͵�HH:mm:ss��ʽ��ʱ��
		SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
		return sdf.format(new Date(getTime()));
	}
}

class node {// �����Ϣ
	int NO;
	int depth;

	public node(int _NO, int _depth) {
		// Requires:int���͵Ľ���,int���͵������Ϣ
		// Modifies:����һ���µ�node�����޸��˴˶����NO,depth����
		// Effects:������һ���µ�node���󲢳�ʼ��
		NO = _NO;
		depth = _depth;
	}
}

class guiInfo {
	public int[][] map;
	int[][] graph = new int[6405][6405];// �ڽӾ���
	int[][] D = new int[6405][6405];// �����i��j����С·��ֵ

	public void initmatrix() {// ��ʼ���ڽӾ���
		// Requires:��
		// Modifies:graph[][]
		// Effects:���ڽӾ��󸳳�ֵ
		int MAXNUM = gv.MAXNUM;
		for (int i = 0; i < 6400; i++) {
			for (int j = 0; j < 6400; j++) {
				if (i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = MAXNUM;
			}
		}
		for (int i = 0; i < 80; i++) {
			for (int j = 0; j < 80; j++) {
				if (map[i][j] == 1 || map[i][j] == 3) {
					graph[i * 80 + j][i * 80 + j + 1] = 1;
					graph[i * 80 + j + 1][i * 80 + j] = 1;
				}
				if (map[i][j] == 2 || map[i][j] == 3) {
					graph[i * 80 + j][(i + 1) * 80 + j] = 1;
					graph[(i + 1) * 80 + j][i * 80 + j] = 1;
				}
			}
		}
	}

	public void pointbfs(int root) {// ��������������
		// Requires:int���͵ĵ��root
		// Modifies:D[][],System.out
		// Effects:��������ͼ���й�������������������㵽root֮������·��Ϣ��������D[][]��
		int[] offset = new int[] { 0, 1, -1, 80, -80 };
		Vector<node> queue = new Vector<node>();
		boolean[] view = new boolean[6405];
		for (int i = 0; i < 6400; i++) {
			for (int j = 0; j < 6400; j++) {
				if (i == j) {
					D[i][j] = 0;
				} else {
					D[i][j] = graph[i][j];// ����ֵ
				}
			}
		}
		int x = root;// ��ʼ���е���bfs
		for (int i = 0; i < 6400; i++)
			view[i] = false;
		queue.add(new node(x, 0));
		while (queue.size() > 0) {
			node n = queue.get(0);
			view[n.NO] = true;
			for (int i = 1; i <= 4; i++) {
				int next = n.NO + offset[i];
				if (next >= 0 && next < 6400 && view[next] == false && graph[n.NO][next] == 1) {
					view[next] = true;
					queue.add(new node(next, n.depth + 1));// �����������
					D[x][next] = n.depth + 1;
					D[next][x] = n.depth + 1;
				}
			}
			queue.remove(0);// �˳�����
		}
		// ��������
		int count = 0;
		for (int i = 0; i < 6400; i++) {
			if (D[i][x] == gv.MAXNUM) {
				count++;
			}
		}
		if (count > 0) {
			System.out.println("��ͼ��������ͨ��,�����˳�");
			System.exit(1);
		}
	}

	public int distance(int x1, int y1, int x2, int y2) {// ʹ��bfs��������֮��ľ���
		pointbfs(x1 * 80 + y1);
		return D[x1 * 80 + y1][x2 * 80 + y2];
	}
}

class guitaxi {
	public int x = 1;
	public int y = 1;
	public int status = -1;
}

class guigv {
	public static guiInfo m = new guiInfo();// ��ͼ����
	public static CopyOnWriteArrayList<guitaxi> taxilist = new CopyOnWriteArrayList<guitaxi>();// ���⳵�б�
	public static CopyOnWriteArrayList<Point> srclist = new CopyOnWriteArrayList<Point>();// �������б�
	public static HashMap<String,Integer> flowmap = new HashMap<String,Integer>();//��ǰ����
	public static HashMap<String,Integer> memflowmap = new HashMap<String,Integer>();//֮ǰͳ�Ƶ�����
	/* GUI */
	public static JPanel drawboard;
	public static int[][] colormap;
	public static int[][] lightmap;
	public static boolean redraw = false;
	public static int xoffset = 0;
	public static int yoffset = 0;
	public static int oldxoffset = 0;
	public static int oldyoffset = 0;
	public static int mousex = 0;
	public static int mousey = 0;
	public static double percent = 1.0;
	public static boolean drawstr = false;
	public static boolean drawflow=false;//�Ƿ����������Ϣ
	private static String Key(int x1,int y1,int x2,int y2){//����Ψһ��Key
		return ""+x1+","+y1+","+x2+","+y2;
	}
	public static void AddFlow(int x1,int y1,int x2,int y2){//����һ����·����
		synchronized (guigv.flowmap) {
			//��ѯ֮ǰ����������
			int count=0;
			count=guigv.flowmap.get(Key(x1,y1,x2,y2))==null ? 0 :guigv.flowmap.get(Key(x1,y1,x2,y2));
			//�������
			guigv.flowmap.put(Key(x1,y1,x2,y2), count+1);
			guigv.flowmap.put(Key(x2,y2,x1,y1), count+1);
		}
	}
	public static int GetFlow(int x1,int y1,int x2,int y2){//��ѯ������Ϣ
		synchronized (guigv.memflowmap) {
			return guigv.memflowmap.get(Key(x1,y1,x2,y2))==null ? 0 :guigv.memflowmap.get(Key(x1,y1,x2,y2));
		}
	}
	@SuppressWarnings("unchecked")
	public static void ClearFlow(){//���������Ϣ
		synchronized (guigv.flowmap) {
			synchronized(guigv.memflowmap){
				guigv.memflowmap=(HashMap<String, Integer>) guigv.flowmap.clone();
				guigv.flowmap=new HashMap<String, Integer>();
				
			}
		}
	}
}

class DrawBoard extends JPanel {// ��ͼ����
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2D = (Graphics2D) g;
		brush.draw(g2D);
	}
}

class myform extends JFrame {// �ҵĴ������
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int left = 100;
	private int top = 100;
	private int width = 630;
	private int height = 600;

	public myform() {
		super();
		/* ���ð�ť���� */
		// button1
		JButton button1 = new JButton();// ����һ����ť
		button1.setBounds(10, 515, 100, 40);// ���ð�ť��λ��
		button1.setText("����");// ���ð�ť�ı���
		button1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				guigv.xoffset = 0;
				guigv.yoffset = 0;
				guigv.oldxoffset = 0;
				guigv.oldyoffset = 0;
				guigv.percent = 1.0;
				guigv.drawboard.repaint();
			}
		});
		// button2
		JButton button2 = new JButton();// ����һ����ť
		button2.setBounds(120, 515, 100, 40);// ���ð�ť��λ��
		button2.setText("�Ŵ�");// ���ð�ť�ı���
		button2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				guigv.percent += 0.1;
				guigv.drawboard.repaint();
			}
		});
		// button3
		JButton button3 = new JButton();// ����һ����ť
		button3.setBounds(230, 515, 100, 40);// ���ð�ť��λ��
		button3.setText("��С");// ���ð�ť�ı���
		button3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (guigv.percent > 0.1)
					guigv.percent -= 0.1;
				guigv.drawboard.repaint();
			}
		});
		// button4
		JButton button4 = new JButton();
		button4.setBounds(340, 515, 100, 40);
		button4.setText("����켣");
		button4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// ���colormap
				for (int i = 0; i < 85; i++) {
					for (int j = 0; j < 85; j++) {
						guigv.colormap[i][j] = 0;
					}
				}
				guigv.drawboard.repaint();
			}
		});
		/* ���ø�ѡ������ */
		JCheckBox check1 = new JCheckBox("��ʾλ��");
		check1.setBounds(450, 515, 80, 40);
		check1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				guigv.drawstr = check1.isSelected();
				guigv.drawboard.repaint();
			}
		});
		JCheckBox check2 = new JCheckBox("��ʾ����");
		check2.setBounds(530, 515, 80, 40);
		check2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				guigv.drawflow = check2.isSelected();
				guigv.drawboard.repaint();
			}
		});
		/* ���û�ͼ������ */
		DrawBoard drawboard = new DrawBoard();// �����µĻ�ͼ��
		drawboard.setBounds(10, 10, 500, 500);// ���ô�С
		drawboard.setBorder(BorderFactory.createLineBorder(Color.black, 1));// ���ñ߿�
		drawboard.setOpaque(true);
		drawboard.addMouseListener(new MouseListener() {
			public void mousePressed(MouseEvent e) {// �������
				guigv.redraw = true;
				guigv.mousex = e.getX();
				guigv.mousey = e.getY();
			}

			public void mouseReleased(MouseEvent e) {// �ɿ����
				guigv.oldxoffset = guigv.xoffset;
				guigv.oldyoffset = guigv.yoffset;
				guigv.redraw = false;
			}

			@Override
			public void mouseClicked(MouseEvent e) {
			}

			@Override
			public void mouseEntered(MouseEvent e) {
			}

			@Override
			public void mouseExited(MouseEvent e) {
			}
		});
		drawboard.addMouseMotionListener(new MouseMotionAdapter() {// �������϶�
			public void mouseDragged(MouseEvent e) {
				if (guigv.redraw == true) {
					guigv.xoffset = guigv.oldxoffset + e.getX() - guigv.mousex;
					guigv.yoffset = guigv.oldyoffset + e.getY() - guigv.mousey;
					guigv.drawboard.repaint();
				}
			}
		});
		drawboard.addMouseWheelListener(new MouseWheelListener() {// ���������
			public void mouseWheelMoved(MouseWheelEvent e) {
				if (e.getWheelRotation() == 1) {// ������ǰ
					if (guigv.percent > 0.1)
						guigv.percent -= 0.1;
					guigv.drawboard.repaint();
				} else if (e.getWheelRotation() == -1) {// �������
					guigv.percent += 0.1;
					guigv.drawboard.repaint();
				}
			}
		});
		guigv.drawboard = drawboard;// ���һ��drawboard������

		/* ���ô������� */
		setTitle("ʵʱ�鿴");// ���ô������
		setLayout(null);// ʹ�þ��Բ���
		setBounds(left, top, width, height);// ���ô���λ�ô�С

		/* ��ӿؼ�����ʾ���� */
		Container c = getContentPane();// ���һ������
		c.add(button1);// ���button1
		c.add(button2);
		c.add(button3);
		c.add(button4);
		c.add(check1);
		c.add(check2);
		c.add(drawboard);
		setVisible(true);// ʹ����ɼ�
		setAlwaysOnTop(true);// ���ô����ö�
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);// ����Ĭ�Ϲرշ�ʽ
	}
}

class brush {// ����
	public static int[][] colormap = new int[85][85];

	public static void draw(Graphics2D g) {
		boolean drawcolor = true;
		int factor = (int) (35 * guigv.percent);
		int width = (int) (20 * guigv.percent);
		int xoffset = -5;
		int yoffset = 3;
		// ����һ����⳵λ����Ϣ�����г��⳵��λ�ñ���1
		int[][] taximap = new int[85][85];
		// ���colormap������
		guigv.colormap = colormap;
		// ���ó��⳵λ��
		for (int i = 0; i < 80; i++)
			for (int j = 0; j < 80; j++) {
				taximap[i][j] = -1;
			}
		for (int i = 0; i < guigv.taxilist.size(); i++) {
			guitaxi gt = guigv.taxilist.get(i);
			if (gt.status > -1) {
				// System.out.println("####"+gt.x+" "+gt.y);
				taximap[gt.x][gt.y] = gt.status;
				if (gt.status == 1) {
					colormap[gt.x][gt.y] = 1;// ·��Ⱦɫ
				}
			}
		}
		// synchronized (guigv.m.taxilist) {
		// for (taxiInfo i : guigv.m.taxilist) {
		// taximap[i.nowPoint.x][i.nowPoint.y] = 1;
		// if (i.state == STATE.WILL || i.state == STATE.RUNNING) {
		// taximap[i.nowPoint.x][i.nowPoint.y] = 2;
		// colormap[i.nowPoint.x][i.nowPoint.y] = 1;// ·��Ⱦɫ
		// }
		// }
		// }
		// ...

		for (int i = 0; i < 80; i++) {
			for (int j = 0; j < 80; j++) {
				if (j < 10) {
					xoffset = -5;
					yoffset = 3;
				} else {
					xoffset = -7;
					yoffset = 3;
				}
				g.setStroke(new BasicStroke(2));
				g.setFont(new Font("Arial", Font.PLAIN, (int) (10 * guigv.percent)));
				if (guigv.m.map[i][j] == 2 || guigv.m.map[i][j] == 3) {
					if (drawcolor && colormap[i][j] == 1 && colormap[i + 1][j] == 1)
						g.setColor(Color.RED);
					else
						g.setColor(Color.BLACK);
					int memj=(int) ((j * factor + guigv.xoffset) * guigv.percent);
					g.drawLine(memj,
							(int) ((i * factor + guigv.yoffset) * guigv.percent),
							memj,
							(int) (((i + 1) * factor + guigv.yoffset) * guigv.percent));
					//���Ƶ�·����
					if(guigv.drawflow){
						g.setColor(Color.BLUE);
						g.drawString(""+guigv.GetFlow(i, j, i+1, j), memj,
								(int) (((i + 0.5) * factor + guigv.yoffset) * guigv.percent));
					}
				}
				if (guigv.m.map[i][j] == 1 || guigv.m.map[i][j] == 3) {
					if (drawcolor && colormap[i][j] == 1 && colormap[i][j + 1] == 1)
						g.setColor(Color.RED);
					else
						g.setColor(Color.BLACK);
					int memi=(int) ((i * factor + guigv.yoffset) * guigv.percent);
					g.drawLine((int) ((j * factor + guigv.xoffset) * guigv.percent),
							memi,
							(int) (((j + 1) * factor + guigv.xoffset) * guigv.percent),
							memi);
					//���Ƶ�·����
					if(guigv.drawflow){
						g.setColor(Color.BLUE);
						g.drawString(""+guigv.GetFlow(i, j, i, j+1), (int) (((j + 0.5) * factor + guigv.xoffset) * guigv.percent),
								memi);
					}
				}
				int targetWidth;
				if (taximap[i][j] == 3) {
					g.setColor(Color.GREEN);
					targetWidth = 2;
				} else if (taximap[i][j] == 2) {
					g.setColor(Color.RED);
					targetWidth = 2;
				} else if (taximap[i][j] == 1) {
					g.setColor(Color.BLUE);
					targetWidth = 2;
				} else if (taximap[i][j] == 0) {
					g.setColor(Color.YELLOW);
					targetWidth = 2;
				} else {
					g.setColor(Color.BLACK);
					targetWidth = 1;
				}
				int cleft = (int) ((j * factor - width / 2 + guigv.xoffset) * guigv.percent);
				int ctop = (int) ((i * factor - width / 2 + guigv.yoffset) * guigv.percent);
				int cwidth = (int) (width * guigv.percent) * targetWidth;
				if (targetWidth > 1) {
					cleft = cleft - (int) (cwidth / 4);
					ctop = ctop - (int) (cwidth / 4);
				}
				// g.fillOval((int)((j*factor-width/2+guigv.xoffset)*guigv.percent),(int)((i*factor-width/2+guigv.yoffset)*guigv.percent),(int)(width*guigv.percent)*targetWidth,(int)(width*guigv.percent)*targetWidth);
				g.fillOval(cleft, ctop, cwidth, cwidth);// ���Ƶ�
				//���ƺ��̵�
				if(guigv.lightmap[i][j]==1){//��������Ϊ�̵�
					g.setColor(Color.GREEN);
					g.fillRect(cleft-cwidth/4, ctop+cwidth/4, cwidth/2, cwidth/8);
					g.setColor(Color.RED);
					g.fillRect(cleft+cwidth/8, ctop-cwidth/4, cwidth/8, cwidth/2);
				}
				else if(guigv.lightmap[i][j]==2){//��������Ϊ���
					g.setColor(Color.RED);
					g.fillRect(cleft-cwidth/4, ctop+cwidth/4, cwidth/2, cwidth/8);
					g.setColor(Color.GREEN);
					g.fillRect(cleft+cwidth/8, ctop-cwidth/4, cwidth/8, cwidth/2);
				}
				// ���srclist�еĵ�
				for (Point p : guigv.srclist) {
					g.setColor(Color.RED);
					int x = p.x;
					int y = p.y;
					g.drawLine((int) (((y - 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x - 2) * factor + guigv.yoffset) * guigv.percent),
							(int) (((y + 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x - 2) * factor + guigv.yoffset) * guigv.percent));
					g.drawLine((int) (((y + 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x - 2) * factor + guigv.yoffset) * guigv.percent),
							(int) (((y + 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x + 2) * factor + guigv.yoffset) * guigv.percent));
					g.drawLine((int) (((y + 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x + 2) * factor + guigv.yoffset) * guigv.percent),
							(int) (((y - 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x + 2) * factor + guigv.yoffset) * guigv.percent));
					g.drawLine((int) (((y - 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x + 2) * factor + guigv.yoffset) * guigv.percent),
							(int) (((y - 2) * factor + guigv.xoffset) * guigv.percent),
							(int) (((x - 2) * factor + guigv.yoffset) * guigv.percent));
				}
				if (guigv.drawstr == true) {
					g.setColor(Color.WHITE);
					g.setFont(new Font("Arial", Font.PLAIN, (int) (8 * guigv.percent)));
					g.drawString("" + i + "," + j, (int) ((j * factor + xoffset + guigv.xoffset) * guigv.percent),
							(int) ((i * factor + yoffset + guigv.yoffset) * guigv.percent));
				}
				
			}
		}
	}
}

class processform extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JProgressBar progressBar = new JProgressBar();
	JLabel label1 = new JLabel("BFS����", SwingConstants.CENTER);

	public processform() {
		super();
		// �������������ڴ������
		getContentPane().add(progressBar, BorderLayout.NORTH);
		getContentPane().add(label1, BorderLayout.CENTER);
		progressBar.setMinimum(0);
		progressBar.setMaximum(100);
		progressBar.setStringPainted(true);
		// ���ô���������Է���
		setBounds(100, 100, 100, 100);
		setAlwaysOnTop(true);// ���ô����ö�
		setVisible(true);
	}
}

class debugform extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JTextArea text1 = new JTextArea();

	public debugform() {
		super();
		getContentPane().add(text1);
		setBounds(0, 100, 500, 100);
		setAlwaysOnTop(true);
		setVisible(true);
	}
}

class TaxiGUI {// GUI�ӿ���
	public void LoadMap(int[][] map, int size) {
		guigv.m.map = new int[size + 5][size + 5];
		guigv.lightmap=new int[size+5][size+5];//��ʼ�����̵�
		// ���Ƶ�ͼ
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				guigv.m.map[i][j] = map[i][j];
			}
		}
		// ��ʼ���Ƶ�ͼ,��ÿ100msˢ��
		new myform();
		Thread th = new Thread(new Runnable() {
			public void run() {
				int timewindow=200;//ʱ�䴰����Ϊ200ms
				int timecount=0;//��ʱ
				while (true) {
					gv.stay(100);
					timecount+=100;
					if(timecount>timewindow){
						timecount=0;
						//���¼�¼������Ϣ
						guigv.ClearFlow();
					}
					guigv.drawboard.repaint();
				}
			}
		});
		th.start();
		guigv.m.initmatrix();// ��ʼ���ڽӾ���
	}
	public void SetTaxiStatus(int index, Point point, int status) {
		guitaxi gt = guigv.taxilist.get(index);
		guigv.AddFlow(gt.x, gt.y, point.x, point.y);//ͳ������
		gt.x = point.x;
		gt.y = point.y;
		gt.status = status;
	}

	public void RequestTaxi(Point src, Point dst) {
		// ��src��Χ���
		guigv.srclist.add(src);
		// �������·����ֵ,ͨ��һ�����ڵ���
		int distance = guigv.m.distance(src.x, src.y, dst.x, dst.y);
		debugform form1 = new debugform();
		form1.text1.setText("��(" + src.x + "," + src.y + ")��(" + dst.x + "," + dst.y + ")�����·��������" + distance);
	}
	public void SetLightStatus(Point p,int status){//���ú��̵� status 0 û�к��̵� 1 ��������Ϊ�̵� 2 ��������Ϊ���
		guigv.lightmap[p.x][p.y]=status;
	}
	public void SetRoadStatus(Point p1, Point p2, int status) {// status 0�ر� 1��
		synchronized(guigv.m.map){
			int di = p1.x - p2.x;
			int dj = p1.y - p2.y;
			Point p = null;
			if (di == 0) {// ��ͬһˮƽ����
				if (dj == 1) {// p2-p1
					p = p2;
				} else if (dj == -1) {// p1-p2
					p = p1;
				} else {
					return;
				}
				if (status == 0) {// �ر�
					if (guigv.m.map[p.x][p.y] == 3) {
						guigv.m.map[p.x][p.y] = 2;
					} else if (guigv.m.map[p.x][p.y] == 1) {
						guigv.m.map[p.x][p.y] = 0;
					}
				} else if (status == 1) {// ��
					if (guigv.m.map[p.x][p.y] == 2) {
						guigv.m.map[p.x][p.y] = 3;
					} else if (guigv.m.map[p.x][p.y] == 0) {
						guigv.m.map[p.x][p.y] = 1;
					}
				}
			} else if (dj == 0) {// ��ͬһ��ֱ����
				if (di == 1) {// p2-p1
					p = p2;
				} else if (di == -1) {// p1-p2
					p = p1;
				} else {
					return;
				}
				if (status == 0) {// �ر�
					if (guigv.m.map[p.x][p.y] == 3) {
						guigv.m.map[p.x][p.y] = 1;
					} else if (guigv.m.map[p.x][p.y] == 2) {
						guigv.m.map[p.x][p.y] = 0;
					}
				} else if (status == 1) {// ��
					if (guigv.m.map[p.x][p.y] == 1) {
						guigv.m.map[p.x][p.y] = 3;
					} else if (guigv.m.map[p.x][p.y] == 0) {
						guigv.m.map[p.x][p.y] = 2;
					}
				}
			}
			return;
		}
	}

	public TaxiGUI() {
		// ��ʼ��taxilist
		for (int i = 0; i < 101; i++) {
			guitaxi gt = new guitaxi();
			guigv.taxilist.add(gt);
		}
	}
}