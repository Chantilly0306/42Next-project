#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <limits.h>

struct s_data;
struct s_pile_data;

typedef enum e_complex
{
    BENCH = 1,
    ADAPTATIVE,
    SIMPLE,
    MEDIUM,
    COMPLEX
}       t_complex;

typedef void (*t_tag_ft)(struct s_data *, struct s_pile_data *);

// typedef struct s_tag_ft
// {

// } t_tag_ft;

typedef struct s_pile
{
    long int num;
    int idx;
    int in_lis;
    struct s_pile *prev;
    struct s_pile *next;
}   t_pile;

typedef struct s_lis
{
    
    t_pile *lis_cur;
    struct s_lis *lis_start;
	struct s_lis *lis_end;
    struct s_lis *lis_prev;
    struct s_lis *lis_next;
    size_t lis_len;
}   t_lis;

typedef struct s_pile_tab
{
    long int val;
    t_pile *pile_ptr;
}   t_pile_tab;

typedef struct s_bench_data
{
	int mistakes;
	int pairs;
	float disorder;
	float disorder_percent;
    int total_ops;
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
}				t_bench_data;

// LIS - Longest Increasing Subsequence

typedef struct s_lis_data
{
    t_pile *pile_a;
    t_lis *pile_max_lis;
    size_t max_lis_len;
    int idx_max_lis;
    t_lis *tab_lis;
}   t_lis_data;

typedef struct s_pile_data
{
    t_pile  *a;
    t_pile  *b;
    size_t a_len;
    size_t b_len;
    size_t lis_len;
    struct s_pile *first_a;
    struct s_pile *first_b;
    struct s_pile *last_a;
    struct s_pile *last_b;
}   t_pile_data;

typedef struct s_data
{
    const char *nb_start;
    char *nb_end;
    t_complex   strategy;
    int is_bench;
    int in_lis_total;
    t_pile *tmp;
    t_pile *ref;
    t_pile_tab  *tab;
    t_tag_ft    *tag_tab;
	t_bench_data *bench_data;
    int         ac;
    char        **av;
    int         start_idx;
}   t_data;

// typedef struct s_bench
// {

// }   t_bench;


// typedef (*complex_dispatcher)(t_data *, t_pile_data *);

// Diverse print

void print_pile(t_pile *pile, const char *s);
void print_pile_idx(t_pile *pile, const char *s);
void print_tab(t_pile_tab *tab, size_t len, const char *s);
void print_pile_lis(t_pile *pile, const char *s);
void print_lis(t_lis *lis, const char *s);
void print_bench_data(t_bench_data *bench_data);

int print_report(const char *fm, ...);

//	--			_DATAS_			--


//  _initiation

//  *_data 
void data_init(t_data *data, int ac, char **av);
void complex_and_bench_init(t_data *data, int ac, char **av);

//  *_pile data
void pile_init(t_pile_data *pile);

//  *_lis data
void lis_tab_init(t_lis_data *lis_data, t_pile_data *pile);
void lis_init(t_lis *tab_lis, t_pile *pile_a);
void lis_new_add(t_lis *prev, t_pile *cur);

// *_bench data
void bench_data_init(t_data *data, t_pile_data *pile);

//  _piles
t_pile *pile_newadd(t_pile_data *pile, long int num);
void pile_to_tab(t_data *data, t_pile_data *pile);

//  _free


// 	--			_PARSING_		--	


//  _pile parsing
void pile_parsing(t_data *data, t_pile_data *pile);
void pile_fill(t_data *data, t_pile_data *pile);

//  _pile index
void pile_index(t_data *data, t_pile_data *pile);
void pile_to_tab(t_data *data, t_pile_data *pile);
void quick_sort(t_pile_tab *tab, int low, int high);
void index_to_pile(t_pile_tab *tab, size_t tab_len);

// _pile_longuest_increasing_subsequences
void pile_lis(t_data *data, t_pile_data *pile);
void create_lis(t_pile_data *pile, t_lis *lis);
void pile_lis_index(t_lis *final_lis);

// 	--			_PUSHSWAP_		--	

int	step_operation(t_data *data, t_pile_data *pile, char *step);

// _pushswap_moves

// _pushswap_algorithms

// *_adaptative
// *_simple
void	sort_selection(t_data *data, t_pile_data *pile);
// *_medium
void	sort_chunk(t_data *data, t_pile_data *pile);
// *_complex


// 	--			_UTILS_		--	
int is_double(long int num, t_pile_data *pile);
void error_exit(t_data *data, t_pile_data *pile);
t_pile *get_next(t_pile *current, t_pile *first);
t_pile *get_prev(t_pile *current, t_pile *last);

#endif
