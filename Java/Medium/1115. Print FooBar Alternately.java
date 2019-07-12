class FooBar {
    private int n;
    private boolean next = false;
    public FooBar(int n) {
        this.n = n;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(next) { 
                try { 
                    wait(); 
                } 
                catch(InterruptedException e) { 
                    e.printStackTrace(); 
                } 
            } 
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            next = true;
            notify();
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while(!next) { 
                try { 
                    wait(); 
                } 
                catch(InterruptedException e) { 
                    e.printStackTrace(); 
                } 
            } 
            
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            next = false;
            notify();
        }
    }
}
