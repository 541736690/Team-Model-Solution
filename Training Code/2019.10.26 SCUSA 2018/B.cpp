//
// Created by 54173 on 10/26/2019.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#define ld long double

using namespace std;
const int maxn = 100000;
const ld eps = 0.5;

string noteName[12][2];

void init()
{
    noteName[0][0] = "A";
    noteName[1][0] = "A#";
    noteName[1][1] = "Bb";
    noteName[2][0] = "B";
    noteName[3][0] = "C";
    noteName[4][0] = "C#";
    noteName[4][1] = "Db";
    noteName[5][0] = "D";
    noteName[6][0] = "D#";
    noteName[6][1] = "Eb";
    noteName[7][0] = "E";
    noteName[8][0] = "F";
    noteName[9][0] = "F#";
    noteName[9][1] = "Gb";
    noteName[10][0] = "G";
    noteName[11][0] = "G#";
    noteName[11][1] = "Ab";

    for (int i=0; i<12; i++)
        if (noteName[i][1]=="")
            noteName[i][1] = noteName[i][0];
}

int fromFrequencyToNodeID(ld frequency)
{
    return (((int) floor(log2(frequency/440.0)*12+eps))%12+12)%12;
}

int n;
set<int> notes;
vector<int> noteVec;
vector<int> legalSet;

int appear[maxn+1];

int majorDiff[6] = {2,2,1,2,2,2};
int minorDiff[6] = {2,1,2,2,1,2};
int setbit(int x,int n)
{
    return (x|(1<<n));
}

int createMajor(int x)
{
    int mask = 0;
    mask = setbit(mask,x);
    for (int i=0; i<6; i++){
        x=(x+majorDiff[i])%12;
        mask = setbit(mask,x);
    }

    return mask;
}

int createMinor(int x)
{
    int mask = 0;
    mask = setbit(mask,x);
    for (int i=0; i<6; i++) {
        x = (x + minorDiff[i]) % 12;
        mask = setbit(mask,x);
    }

    return mask;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    init();
    cin >> n;
    for (int i=1; i<=n; i++) {
        ld f;
        cin >> f;
        appear[i] = fromFrequencyToNodeID(f);
        notes.insert(appear[i]);
    }

    legalSet.push_back(createMajor(10));
    legalSet.push_back(createMajor(3));
    legalSet.push_back(createMajor(6));
    legalSet.push_back(createMinor(9));
    legalSet.push_back(createMinor(10));

    int currentMask = 0;
    for (int x: notes)
        currentMask = setbit(currentMask,x);

    int vt = 0;
    int cnt = 0;
    for (int i=0; i<legalSet.size(); i++){
        int mask = legalSet[i];
        if ((currentMask&mask)==currentMask)
        {
            cnt++;
            vt = i;
        }
    }


    if (cnt!=1)
        cout << "cannot determine key";
    else
    {
        if (vt<3)
        {
            int major;
            if (vt==0)
                major=10;
            else
                if (vt==1)
                    major=3;
                else
                    if (vt==2)
                        major=6;
            int id2;
            if (vt==2)
                id2=1;
            else
                id2=0;
            cout << noteName[major][id2] << " major\n";
            notes.clear();
            for (int i=1; i<=n; i++)
            {
                int id = appear[i];
                cout << noteName[id][id2] << '\n';
            }
        }
        else
        {
            int minor;
            if (vt==3)
                minor=9;
            else
                minor=10;
            int id2;
            if (vt==3)
                id2=0;
            else
                id2=1;
            cout << noteName[minor][id2] << " minor\n";
            notes.clear();

            for (int i=1; i<=n; i++)
            {
                int id = appear[i];
                cout << noteName[id][id2] << '\n';
            }
        }
    }


    return 0;
}
