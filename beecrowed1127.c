#include <stdio.h>
#include <string.h>

// Map notes to values 0-11
int get_note_value(char *note) {
    if (strcmp(note, "C") == 0 || strcmp(note, "B#") == 0) return 0;
    if (strcmp(note, "C#") == 0 || strcmp(note, "Db") == 0) return 1;
    if (strcmp(note, "D") == 0) return 2;
    if (strcmp(note, "D#") == 0 || strcmp(note, "Eb") == 0) return 3;
    if (strcmp(note, "E") == 0 || strcmp(note, "Fb") == 0) return 4;
    if (strcmp(note, "F") == 0 || strcmp(note, "E#") == 0) return 5;
    if (strcmp(note, "F#") == 0 || strcmp(note, "Gb") == 0) return 6;
    if (strcmp(note, "G") == 0) return 7;
    if (strcmp(note, "G#") == 0 || strcmp(note, "Ab") == 0) return 8;
    if (strcmp(note, "A") == 0) return 9;
    if (strcmp(note, "A#") == 0 || strcmp(note, "Bb") == 0) return 10;
    if (strcmp(note, "B") == 0 || strcmp(note, "Cb") == 0) return 11;
    return -1;
}

void compute_lps(int *pat, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
}

int kmp_search(int *txt, int n, int *pat, int m) {
    if (m == 0) return 1;
    int lps[m];
    compute_lps(pat, m, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) { i++; j++; }
        if (j == m) return 1; // Found
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return 0;
}

int main() {
    int M, T;
    while (scanf("%d %d", &M, &T) && (M != 0 || T != 0)) {
        int song[M], snippet[T];
        char note[4];
        for (int i = 0; i < M; i++) { scanf("%s", note); song[i] = get_note_value(note); }
        for (int i = 0; i < T; i++) { scanf("%s", note); snippet[i] = get_note_value(note); }

        if (T == 1) { // Single note snippet always "plagiarizes" any note
            printf("S\n");
            continue;
        }

        int song_intervals[M - 1], snippet_intervals[T - 1];
        for (int i = 0; i < M - 1; i++) song_intervals[i] = (song[i+1] - song[i] + 12) % 12;
        for (int i = 0; i < T - 1; i++) snippet_intervals[i] = (snippet[i+1] - snippet[i] + 12) % 12;

        if (kmp_search(song_intervals, M - 1, snippet_intervals, T - 1)) printf("S\n");
        else printf("N\n");
    }
    return 0;
}

