package oo6;

import java.util.Random;

import oo6.Map;
import oo6.FileWrite;

import java.awt.Point;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;

class FileWrite{
	public static void tofile(String str){
		Charset charset = Charset.forName("US-ASCII");
		try{
			FileOutputStream out=new FileOutputStream("result.txt",true);
			str=str+"\r\n";
			out.write(str.getBytes(charset));
			out.close();
		}catch (IOException x ){
			System.err.format("IOException:%s%n", x);
		}
	}
}
public class Taxi extends Thread {	
	/*Overview
	 * 根据自身状态和waitinglist移动自身
	 *  * \all int i;
	 * 0<i&i<taxinumber;
	 * repOK<==>!((TAXILIST[i].num<0||TAXILIST[i].num>=taxinumber)
	 *			||(TAXILIST[i].spot.X<0||TAXILIST[i].spot.X>=Map.maxofmap||TAXILIST[i].spot.Y<0||TAXILIST[i].spot.Y>=Map.maxofmap)
	 *			||(TAXILIST[i].honest<0)
	 *			||(!(TAXILIST[i].state.equals("waiting")||TAXILIST[i].state.equals("heading")||TAXILIST[i].state.equals("stop")||TAXILIST[i].state.equals("stop1")||TAXILIST[i].state.equals("stop2")||TAXILIST[i].state.equals("pickingup"))))==ture;
	 * 
	 * */
	Point1 spot;
	int num = 0;
	int honest =0;
	TaxiGUI gui;
	String state;
	ArrayList<Point1> waitinglist1 = new ArrayList<Point1>();
	
	static int taxinumber=100;
	//记得要改啊啊啊啊
	static Taxi[] TAXILIST = new Taxi[taxinumber];
	public boolean repOK(){
		/* @Requires:none;
		 * @Modifies:none;
		 * @Effects:check TAXILIST
		 * 			if TAXILIST is right return true 
		 *  */
		for(int i=0;i<taxinumber;i++){
			if(TAXILIST[i].num<0||TAXILIST[i].num>=taxinumber){
				return false;
			}
			if(TAXILIST[i].spot.X<0||TAXILIST[i].spot.X>=Map.maxofmap||TAXILIST[i].spot.Y<0||TAXILIST[i].spot.Y>=Map.maxofmap){
				return false;
			}
			if(TAXILIST[i].honest<0){
				return false;
			}
			if(!(TAXILIST[i].state.equals("waiting")||TAXILIST[i].state.equals("heading")||TAXILIST[i].state.equals("stop")||TAXILIST[i].state.equals("stop1")||TAXILIST[i].state.equals("stop2")||TAXILIST[i].state.equals("pickingup"))){
				return false;
			}
		}
		return true;
		
	}
	
	
	public synchronized void addhonest(int a){
		/* @Requires:int a;
		 * @Modifies:\this.honest;	
		 * @Effects:\this.honest==\old\this.honest+a;		
		 * @THREAD_REQUIRES:\locked(\this.honest);
		 * @THREAD_EFFECTS:\locked();
		 * */
		this.honest+=a;
	}
		
	
	public void waitinglight(String newdir,String olddir,int X,int Y){
		/* @Requires:String newdir,olddir,int XY;
		 * @Modifies:none;	
		 * @Effects:while light !=true do nothing until light==true
		 * */
		while(true){
			if(olddir.equals("UP")){
				if(Light.light[X][Y].sign==0){
					break;
				}
				else{
					System.out.print("");
					if(newdir.equals("RIGHT")||newdir.equals("DOWN")){
						break;
					}
					if(Light.light[X][Y].updown){
						if(newdir.equals("UP")){
							break;
						}
					}
					else if(Light.light[X][Y].leftright){
						if(newdir.equals("LEFT")){
							break;
						}
					}
				}
			}
			else if(olddir.equals("DOWN")){
				if(Light.light[X][Y].sign==0){
					break;
				}
				else{
					System.out.print("");
					if(newdir.equals("LEFT")||newdir.equals("UP")){
						break;
					}
					if(Light.light[X][Y].updown){
						if(newdir.equals("DOWN")){
							break;
						}
					}
					else if(Light.light[X][Y].leftright){
						if(newdir.equals("RIGHT")){
							break;
						}
					}
				}
			}
			else if(olddir.equals("LEFT")){
				if(Light.light[X][Y].sign==0){
					break;
				}
				else{
					System.out.print("");
					if(newdir.equals("UP")||newdir.equals("RIGHT")){
						break;
					}
					if(Light.light[X][Y].updown){
						if(newdir.equals("DOWN")){
							break;
						}
					}
					else if(Light.light[X][Y].leftright){
						if(newdir.equals("LEFT")){
							break;
						}
					}
				}
			}
			else if(olddir.equals("RIGHT")){
				if(Light.light[X][Y].sign==0){
					break;
				}
				else{
		//			System.out.println("updown:"+Light.light[X][Y].updown+" leftright"+Light.light[X][Y].leftright);
					System.out.print("");
					if(newdir.equals("DOWN")||newdir.equals("LEFT")){
						break;
					}
					if(Light.light[X][Y].updown){
						if(newdir.equals("UP")){
							break;
						}
					}
					else if(Light.light[X][Y].leftright){
						if(newdir.equals("RIGHT")){
							break;
						}
					}
				}
			}
		}
	}

	
	public synchronized void addtask(Point1 A, Point1 B){
		/* @Requires:Point1 A,B;
		 * @Modifies:this.waitinglist1;
		 * @Effects:(\this.waitinglist1==\old\this.waitinglist.add(A));
		 * 			(\this.waitinglist1==\old\this.waitinglist.add(B));	
		 * @THREAD_REQUIRES:\locked(\this.waitinglist);
		 * @THREAD_EFFECTS:\locked();
		 * */
		this.waitinglist1.add(A);
		this.waitinglist1.add(B);
	}
	public static void InitTaxiMap(TaxiGUI gui){
		/* @Requires:TaxiGUI gui;
		 * @Modifies:TAXILIST[i];	
		 * @Effects:\all int i;	
		 * 			0<=i&i<=taxinumber;
		 * 			TAXILIST[i]==Taxi(i,0,"waiting",new Point1(r1,r2),gui);	
		 * 			TAXILIST[i].state==waiting;
		 * */
		for(int i=0;i<taxinumber;i++){
			
			int r1 = new Random().nextInt(Map.maxofmap);
			int r2 = new Random().nextInt(Map.maxofmap);	
			/*
			int r1=10;
			int r2=10;
			*/
	//		System.out.println("taxi"+i+"START AT("+r1+","+r2+")");
			TAXILIST[i]=new Taxi(i,0,"waiting",new Point1(r1,r2),gui);		 
		/*	
			if(i==0){
				TAXILIST[i]=new Taxi(i,0,"waiting",new Point1(10,11),gui);
			}
			
			if(i==1){
				TAXILIST[i]=new Taxi(i,0,"waiting",new Point1(11,10),gui);
			}
		*/	
			TAXILIST[i].start();
			
		
		}
	}
	int findmini(int[] directions){
		/* @Requires:int[] directions;
		 * @Modifies:none
		 * @Effects:\all int i;
		 * 			directions[i]!=-1; 
		 * 			\result==(\min int i;0<=i&i<=directions.length;directions[i]);
		 * */
		int min=0;
		int mini=0;
		for(int i=0;i<directions.length;i++){
			if(directions[i]!=-1){
				min=directions[i];
				mini=i;
				break;
			}
		}		
		int h;
		for(h=0;h<directions.length;h++){
			if (directions[h]<min&&directions[h]!=-1){
				min=directions[h];
				mini=h;
			}
		}
		return mini;
	}
	
	int randomfindmini(int[] directions){
		/* @Requires:int[] directions;
		 * @Modifies:none
		 * @Effects:\all int i;
		 * 			directions[i]!=-1; 
		 * 			\result==Random(\all int i;0<i&i<directions.lenght;directions[i]==(\min int i;0<=i&i<=directions.length));
		 * */
		int min=0;
		int mini=0;
		for(int i=0;i<4;i++){
			if(directions[i]!=-1){
				min=directions[i];
				mini=i;
				break;
			}
		}		
		int h;
		for(h=0;h<4;h++){
			if (directions[h]<min&&directions[h]!=-1){
				min=directions[h];
				mini=h;
			}
		}
		int add=0;
		int[] random=new int[4];
		for(int i=0;i<4;i++){
			random[i]=0;
		}
		for(int i=0;i<4;i++){
			if(directions[i]==min){
				random[add++]=i;
			}
		}
		int r3=new Random().nextInt(add);
		return random[r3];
	}
	
	int findlessflow(int[] directions,Point1 spot){
		/* @Requires:int[] directions,Point1 spot;
		 * @Modifies:none
		 * @Effects:\all int i;
		 * 			directions[i]!=-1; 
		 * 			int min==(\min int i;0<=i&i<=directions.length;directions[i]);
		 * 			\result=Random(\all int i;0<i&i<directions.length;flow[i]=(\min int i;0<i&i<4;flow[i]));
		 * */
		int mini=findmini(directions);
		int[] flow=new int[4];
		for(int i=0;i<4;i++){
			flow[i]=-1;
		}
		for(int i=0;i<4;i++){
			if(directions[mini]==directions[i]&&i==0){
				flow[i]=Flow.flow[spot.X][spot.Y].down;
			}
			else if(directions[mini]==directions[i]&&i==1){
				flow[i]=Flow.flow[spot.X][spot.Y].up;
			}
			else if(directions[mini]==directions[i]&&i==2){
				flow[i]=Flow.flow[spot.X][spot.Y].left;
			}
			else if(directions[mini]==directions[i]&&i==3){
				flow[i]=Flow.flow[spot.X][spot.Y].right;
			}
		}
		int minflow=findmini(flow);
		int add=0;
		int[] random = new int[4];
		for(int i=0;i<4;i++){
			random[i]=0;
		}
		for(int i=0;i<4;i++){
			if(flow[i]==flow[minflow]){
				random[add++]=i;
			}
		}
		int r3=new Random().nextInt(add);
		return random[r3];
	}
	public Taxi(int i, int j,String a,Point1 A,TaxiGUI GUI) {
		/* @Requires:int i,j;String a;Point1 A;TaxiGUI GUI;
		 * @Modifies:\this.num,\this.honest,\this.state,\this.spot,\this.gui;
		 * @Effects:\this.num==i;\this.honest==j;\this.state ==a;\this.spot ==A;\this.gui==GUI;
		 * */
		num=i;
		honest=j;
		state =a;
		spot =A;
		gui=GUI;
	}
	public void run(){
		String olddir="UP";
		String newdir="";
		//readme 注明olddir初始
		
		/* @Requires:none
		 * @Modifies:\this.waitinglist1
		 * @Effects:if(state.equals(waiting)) then random walk
		 * 			if(state.equals(heading)||state.equals(pickingup)) then walk follow the waitinglist1
		 * 			if(state.equals(stop)||state.equals(stop1)||state.euals(stop2)) then stop
		 * */
		try{
		long time=0;
		while(true){			
			if(state.equals("waiting")){
				time=System.currentTimeMillis();
				/////////////////////////////////////////////////////////////////waiting状态
				while(state.equals("waiting")){
					
					int[] flow=new int[4];
					for(int i=0;i<4;i++){
						flow[i]=-1;
					}
					int add =0;
					if(Map.map[spot.X][spot.Y].up){			
						flow[1]=Flow.flow[spot.X][spot.Y].up;
					}
					if(Map.map[spot.X][spot.Y].down){	
						flow[0]=Flow.flow[spot.X][spot.Y].down;
					}
					if(Map.map[spot.X][spot.Y].left){
						flow[2]=Flow.flow[spot.X][spot.Y].left;
					}
					if(Map.map[spot.X][spot.Y].right){
			
						flow[3]=Flow.flow[spot.X][spot.Y].right;
					}
					
					int r3 = randomfindmini(flow);
				//	System.out.println(r3);
					//up
					
					if(r3==1){
						Flow.addflow(spot.X, spot.Y,"up");
						Flow.addflow(spot.X-1, spot.Y,"down");
						newdir="UP";
						waitinglight(newdir,olddir,spot.X,spot.Y);
						spot.X--;
						
					}
					//down
					else if(r3==0){
						Flow.addflow(spot.X, spot.Y,"down");
						Flow.addflow(spot.X+1, spot.Y,"up");
						newdir="DOWN";
						waitinglight(newdir,olddir,spot.X,spot.Y);
						spot.X++;
						
					}
					//right
					else if(r3==3){
						Flow.addflow(spot.X, spot.Y,"right");
						Flow.addflow(spot.X, spot.Y+1,"left");
						newdir="RIGHT";
						waitinglight(newdir,olddir,spot.X,spot.Y);
						spot.Y++;
						
					}
					//left
					else if(r3==2){
						Flow.addflow(spot.X, spot.Y,"left");
						Flow.addflow(spot.X, spot.Y-1,"right");
						newdir="LEFT";
						waitinglight(newdir,olddir,spot.X,spot.Y);
						spot.Y--;
						
					}
					
					
					try{
						sleep(200);
					}catch (InterruptedException e) {
						System.out.println("ERROR");
					}
					//up
					if(r3==1){
						Flow.subflow(spot.X+1, spot.Y,"up");
						Flow.subflow(spot.X, spot.Y,"down");
						olddir="UP";
					}
					//down
					else if(r3==0){
						Flow.subflow(spot.X-1, spot.Y,"down");
						Flow.subflow(spot.X, spot.Y,"up");
						olddir="DOWN";
					}
					//right
					else if(r3==3){
						Flow.subflow(spot.X, spot.Y-1,"right");
						Flow.subflow(spot.X, spot.Y,"left");
						olddir="RIGHT";
					}
					//left
					else if(r3==2){
						Flow.subflow(spot.X, spot.Y+1,"left");
						Flow.subflow(spot.X, spot.Y,"right");
						olddir="LEFT";
					}
					
					long time2=System.currentTimeMillis()-time;
					if(time2>=20000){
						state="stop";
					}
//					System.out.println("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
					int STATE=-1;
					if(state.equals("waiting")){
						STATE =2;
					}
					else if(state.equals("pickingup")){
						STATE =3;
					}
					else if(state.equals("stop")){
						STATE =0;
					}
					else if(state.equals("heading")){
						STATE =1;
					}
					gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
					
					
				
					
				//	System.out.println(r3);
					//up
					
					
					
				
		
				}
			}	
			
			
			///////////////////////////////////////////////////////////////////pickingup 状态
			else if(state.equals("pickingup")){
				int STATE=-1;
				if(state.equals("waiting")){
					STATE =2;
				}
				else if(state.equals("pickingup")){
					STATE =3;
				}
				else if(state.equals("stop")){
					STATE =0;
				}
				else if(state.equals("heading")){
					STATE =1;
				}
				gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);			
				if(waitinglist1.isEmpty()){
					System.out.println("picking up error!");					
				}else{
					int i=1;
					ArrayList<Point1> aa=new ArrayList<Point1>();
					Map p =new Map(false, false, false, false);
					aa=p.shortway(waitinglist1.get(0),spot);
					if(aa==null){
						state="stop1";
					}else{
						while(i<=(aa.size()-1)){
							if(Point1.isDOWN(aa.get(i),spot)&&Map.map[spot.X][spot.Y].down){
								i++;
								Flow.addflow(spot.X, spot.Y,"down");
								Flow.addflow(spot.X+1, spot.Y,"up");
								newdir="DOWN";
								
								waitinglight(newdir,olddir,spot.X,spot.Y);
								
								spot=Point1.DOWN(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
								
								
																								
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="DOWN";
								Flow.subflow(spot.X-1, spot.Y,"down");
								Flow.subflow(spot.X, spot.Y,"up");
							}
							else if(Point1.isUP(aa.get(i), spot)&&Map.map[spot.X][spot.Y].up){
								i++;
								Flow.addflow(spot.X, spot.Y,"up");
								Flow.addflow(spot.X-1, spot.Y,"down");
								newdir="UP";
								waitinglight(newdir,olddir,spot.X,spot.Y);
								spot=Point1.UP(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
								
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="UP";
								Flow.subflow(spot.X+1, spot.Y,"up");
								Flow.subflow(spot.X, spot.Y,"down");
							}
							else if(Point1.isRIGHT(aa.get(i), spot)&&Map.map[spot.X][spot.Y].right){
								i++;
								Flow.addflow(spot.X, spot.Y,"right");
								Flow.addflow(spot.X, spot.Y+1,"left");
								
								newdir="RIGHT";
								waitinglight(newdir,olddir,spot.X,spot.Y);
								spot=Point1.RIGHT(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
								
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="RIGHT";
								Flow.subflow(spot.X, spot.Y-1,"right");
								Flow.subflow(spot.X, spot.Y,"left");
							}
							else if(Point1.isLEFT(aa.get(i), spot)&&Map.map[spot.X][spot.Y].left){
								i++;
								Flow.addflow(spot.X, spot.Y,"left");
								Flow.addflow(spot.X, spot.Y-1,"right");
								
								newdir="LEFT";
								waitinglight(newdir,olddir,spot.X,spot.Y);
								spot=Point1.LEFT(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
								
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="LEFT";
								Flow.subflow(spot.X, spot.Y+1,"left");
								Flow.subflow(spot.X, spot.Y,"right");
							}
							else{
								aa.clear();
								aa=p.shortway(waitinglist1.get(0),spot);
								i=1;
							}
						}					
						state="stop1";	
					}
				}
			}
			
			
			/////////////////////////////////////////////////////////////////stop状态
			else if(state.equals("stop")){
				int STATE=-1;
				if(state.equals("waiting")){
					STATE =2;
				}
				else if(state.equals("pickingup")){
					STATE =3;
				}
				else if(state.equals("stop")){
					STATE =0;
				}
				else if(state.equals("heading")){
					STATE =1;
				}
				gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
				try{
					sleep(1000);
				}catch (InterruptedException e) {
					System.out.println("ERROR");
				}			
				state="waiting";
								
			}
			else if(state.equals("stop2")){
				int STATE=-1;
				if(state.equals("waiting")){
					STATE =2;
				}
				else if(state.equals("pickingup")){
					STATE =3;
				}
				else if(state.equals("stop")||state.equals("stop2")){
					STATE =0;
				}
				else if(state.equals("heading")){
					STATE =1;
				}
				gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
				try{
					sleep(1000);
				}catch (InterruptedException e) {
					System.out.println("ERROR");
				}
				state="pickingup";				
			}
			else if(state.equals("stop1")){
				int STATE=-1;
				if(state.equals("waiting")){
					STATE =2;
				}
				else if(state.equals("pickingup")){
					STATE =3;
				}
				else if(state.equals("stop1")||state.equals("stop")||state.equals("stop2")){
					STATE =0;
				}
				else if(state.equals("heading")){
					STATE =1;
				}
				gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
				try{
					sleep(1000);
				}catch (InterruptedException e) {
					System.out.println("ERROR");
				}											
				state="heading";				
			}
			
			///////////////////////////////////////////////////////////////////////heading状态
			else if(state.equals("heading")){ 
				int STATE=-1;
				if(state.equals("waiting")){
					STATE =2;
				}
				else if(state.equals("pickingup")){
					STATE =3;
				}
				else if(state.equals("stop")){
					STATE =0;
				}
				else if(state.equals("heading")){
					STATE =1;
				}
				int i=1;
				gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
				
				if(waitinglist1.isEmpty()){
					System.out.println("heading error!");
				}else{	
					ArrayList<Point1> aa =new ArrayList<Point1>();
					Map p =new Map(false, false, false, false);
					System.out.println("Taxi:"+num+"from("+spot.X+","+spot.Y+")to("+waitinglist1.get(1).X+","+waitinglist1.get(1).Y+")");
					aa=p.shortway(waitinglist1.get(1),waitinglist1.get(0));
					for(int j=0;j<aa.size();j++){
						System.out.println("Taxi:"+num+"("+aa.get(j).X+","+aa.get(j).Y+")");
					}
						while(i<=(aa.size()-1)){
							if(Point1.isDOWN(aa.get(i), spot)&&Map.map[spot.X][spot.Y].down){
								i++;
								Flow.addflow(spot.X, spot.Y,"down");
								Flow.addflow(spot.X+1, spot.Y,"up");
								newdir="DOWN";
								waitinglight(newdir,olddir,spot.X,spot.Y);
								
								spot=Point1.DOWN(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
								
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="DOWN";
								Flow.subflow(spot.X-1, spot.Y,"down");
								Flow.subflow(spot.X, spot.Y,"up");

							}
							else if(Point1.isUP(aa.get(i), spot)&&Map.map[spot.X][spot.Y].up){
								i++;
								Flow.addflow(spot.X, spot.Y,"up");
								Flow.addflow(spot.X-1, spot.Y,"down");
								newdir="UP";
								waitinglight(newdir,olddir,spot.X,spot.Y);
								spot=Point1.UP(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
								
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="UP";
								Flow.subflow(spot.X+1, spot.Y,"up");
								Flow.subflow(spot.X, spot.Y,"down");
							}
							else if(Point1.isRIGHT(aa.get(i), spot)&&Map.map[spot.X][spot.Y].right){
								i++;
								Flow.addflow(spot.X, spot.Y,"right");
								Flow.addflow(spot.X, spot.Y+1,"left");
								newdir="RIGHT";
								waitinglight(newdir,olddir,spot.X,spot.Y);
								spot=Point1.RIGHT(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
								
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="RIGHT";
								Flow.subflow(spot.X, spot.Y-1,"right");
								Flow.subflow(spot.X, spot.Y,"left");
							}
							else if(Point1.isLEFT(aa.get(i), spot)&&Map.map[spot.X][spot.Y].left){
								i++;
								Flow.addflow(spot.X, spot.Y,"left");
								Flow.addflow(spot.X, spot.Y-1,"right");
								newdir="LEFT";
								waitinglight(newdir,olddir,spot.X,spot.Y);	
								spot=Point1.LEFT(spot);
								String sss=("taxi"+num+"move to"+"("+spot.X+","+spot.Y+")");
								FileWrite.tofile(sss);	
								gui.SetTaxiStatus(num, new Point(spot.X,spot.Y), STATE);
															
								try{
									sleep(200);
								}catch (InterruptedException e) {
									System.out.println("ERROR");
								}
								olddir="LEFT";
								Flow.subflow(spot.X, spot.Y+1,"left");
								Flow.subflow(spot.X, spot.Y,"right");
							}
							else{
								aa.clear();
								aa=p.shortway(waitinglist1.get(1),spot);
								i=1;
							}
						}
						honest+=3;
						//read me 标明是执行完毕后信誉才+3
						waitinglist1.remove(0);
						waitinglist1.remove(0);
						if(waitinglist1.isEmpty()){
							state="stop";
						}
						else{
							state="stop2";
						}
						
					
				}
			}
		}
	}catch (Exception e) {
			System.out.println("ERROR");
		}
	}
}
