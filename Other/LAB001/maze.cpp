#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-06-26 13:57

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Maze"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".osu", "w", stdout);
}

void testcase() {
    cout << R"(osu file format v14

[General]
AudioFilename: audio.mp3
AudioLeadIn: 0
PreviewTime: -1
Countdown: 0
SampleSet: Normal
StackLeniency: 0
Mode: 0
LetterboxInBreaks: 0
WidescreenStoryboard: 0

[Editor]
DistanceSpacing: 1.1
BeatDivisor: 4
GridSize: 4
TimelineZoom: 1

[Metadata]
Title:A test of patterns
TitleUnicode:A test of patterns
Artist:me
ArtistUnicode:me
Creator:khanh2
Version:Maze
Source:
Tags:
BeatmapID:5737038
BeatmapSetID:2575812

[Difficulty]
HPDrainRate:10
CircleSize:10
OverallDifficulty:10
ApproachRate:10
SliderMultiplier:3.6
SliderTickRate:8

[Events]
//Background and Video events
//Break Periods
//Storyboard Layer 0 (Background)
//Storyboard Layer 1 (Fail)
//Storyboard Layer 2 (Pass)
//Storyboard Layer 3 (Foreground)
//Storyboard Layer 4 (Overlay)
//Storyboard Sound Samples

[TimingPoints]
0,500,4,1,0,100,1,0

[HitObjects]
)";
    int cnt = 0;
    int x = 0;
    int y = 0;
    cout << 0 << ',' << 0 << ',' << cnt << ",5,0,0:0:0:0:" << el;
    while (cnt < 5000) {

        int nx = mt() % 512;
        int ny = mt() % 385;
        
        while (x != nx && y != ny) {
            if (x > nx) --x;
            else ++x;

            if (y > ny) --y;
            else ++y;

            ++cnt;
            cout << x << ',' << y << ',' << cnt * 13 << ",5,0,0:0:0:0:" << el;
        } 
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}