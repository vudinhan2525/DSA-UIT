void merge(int a[],int n,int b[],int m,int c[]){
		int i = 0;int j = 0;
	    int cnt = 0;
	    while(i < n  && j < m){
	        if(a[i] <= b[j]){
	            c[cnt] = a[i];cnt++;
	            i++;
	        }
	        else if(a[i] > b[j]){
	            c[cnt] = b[j];cnt++;
	            j++;
	        }
	    }
	    while( i < n){
	        c[cnt] = a[i];cnt++;
	        i++;
	    }
	    while( j < m){
	        c[cnt] = b[j];cnt++;
	        j++;
	    }
	}