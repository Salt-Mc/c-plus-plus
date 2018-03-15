#include <bits/stdc++.h>
#include <signal.h>

using namespace std;

void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    printf("Caught segfault at address %p\n", si->si_addr);
    exit(0);
}

int main() {
    long long n;
    long long m;
    long long max = 0;
    struct sigaction sa;

    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);

    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags   = SA_SIGINFO;

    sigaction(SIGSEGV, &sa, NULL);
    cin >> n >> m;
    //cout << "vals " << n << ", " << m << endl;
    long long *arf;
    arf = (long long*)malloc (sizeof(long long) * n);
    for (long long g = 0; g < n ; g++)
        arf[g] = 0;
    
    for(long long a0 = 0; a0 < m; a0++){
        long long a;
        long long b;
        long long k;
        cin >> a >> b >> k;
        try
{

     for (long long j = a-1; j <= b-1; j++)
        {
                arf [j]  += k;
                //cout << "add" << arf[j] << endl;
        }
        /*
        cout << "=================================================\n";
        for (int g = 0; g < n ; g++)
            cout << arf[g] << "\t";
        cout << endl;
        */
    }
    catch (exception& e)
{
    cerr << "Exception catched : " << e.what() << endl;
    break;
}
    }
    for (long long g = 0; g < n ; g++)
        if (arf[g] > max)
            max = arf[g];
    cout << "ANSWER IS " << max << "\n\n";
    
    return 0;
}
