
#include <minishell.h>

//void	ft_signal_cltr_c(int sig)
//{
//    (void) sig;
//    write(2, "\n", 1);
//    rl_on_new_line();
//    rl_replace_line("", 0);
//    rl_redisplay();
//}

//void	set_signals(void)
//{
//    signal(SIGQUIT, ft_signal_cltr_c);   // cntrl '\'
//    signal(SIGTERM, SIG_IGN);           // cntrl D
//    signal(SIGINT, ft_signal_cltr_c);   // cntrl C
//}