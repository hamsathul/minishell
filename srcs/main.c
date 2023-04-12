/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:16:16 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/08 11:18:01 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_manager	g_manager;

static void	init_manager(char *command_line)
{
	g_manager.command_line = command_line;
	g_manager.rc = 0;
	g_manager.quote_error = 0;
}

static void	reset_minishell(t_ast *ast, int std_fd[3])
{
	free_ast(ast);
	reset_std_fd(std_fd);
}

//initializes the shell environment, sets up some initial configurations, and 
//populates the environment with the values from the envp argument
//1. check for command line argumnets and if there are any, exits
//	with an error message indicating that the file or directory specified in 
//	the first argument does not exist
//2. clears the screen, write a splash text sleeps for 1 sec and clears screen again
//3. backup the file descriptors so the shell can restore them later if they are modified
//	by a command
//4. loops through envp and adds each env variable to the
//	shell using add_env function.The get_env_name and get_env_value functions 
//	are used to extract the name and value of each environment variable, respectively.
//5. function checks if the 'OLDPWD' env variable exists and if it does it frees
//	the current value and sets it to NULL. this ensures that 'OLDPWD' is initally unset
//	as it will be set automatically by 'cd' command when the user chages directories.
static void init_minishell(int argc, char **argv, char **envp, int std_fd[3])
{
	t_env	*oldpwd;

	if (argc > 1)
		error_exit(argv[1], strerror(ENOENT), EXIT_ENOENT);
	clear();
	write(STDOUT_FILENO, SPLASHTEXT, 1740);
	sleep(1);
	clear();
	backup_std_fd(std_fd);
	while (*envp)
	{
		add_env(get_env_name(*envp), get_env_value(*envp));
		envp++;
	}
	oldpwd = get_env("OLDPWD");
	if (oldpwd)
	{
		if (oldpwd->value)
			free(oldpwd->value);
		oldpwd->value = NULL;
	}
}
/* initializes the shell environment, enters a loop to read and execute 
user commands, and exits the loop when the user enters an end-of-file 
character. It also handles signal events and frees memory associated 
with various data structures.
1. initialize the shell environment and set up some initial configurations.
2. create an infinite loop untill the shell is exited.
3. setup signal handlers
4. readline function to read a command line from the user, 
	 using the PS1 prompt as a prefix.
5. mini_exit_eof function to check if the user has entered an
	end-of-file character (usually CTRL-D), and if so, exits the shell 
	with a status of EXIT_SUCCESS.
6. If the user has entered a command, the function adds the 
	command line to the shell's history using the add_history function
7. calls the init_manager function to initialize the shell's 
	command manager with the current command line
8. syntax_analyzer function to parse and validate the
	syntax of the command line, and stores the 
	resulting abstract syntax tree (AST) in the ast variable.
9. If the ast variable is not NULL and the shell's exit code is
	EXIT_SUCCESS, the function calls the exec_command_line function
	to execute the command specified by the AST
10. If the ast variable is NULL but there are remaining tokens in
	the input buffer, the function frees the memory associated 
	with the remaining tokens
11. the reset_minishell function to reset the shell environment
	and file descriptors, 
12. frees the memory associated with the command_line variable. */
int	main(int argc, char **argv, char **envp)
{
	int		std_fd[3];
	char	*command_line;
	t_ast	*ast;

	init_minishell(argc, argv, envp, std_fd);
	while (TRUE)
	{
		init_signal();
		command_line = readline(PS1);
		mini_exit_eof(command_line);
		if (*command_line)
		{
			add_history(command_line);
			init_manager(command_line);
			ast = syntax_analyzer();
			//test_ast(ast);
			if (ast && g_manager.exit_code == EXIT_SUCCESS)
				exec_command_line(&ast);
			else if (fetch_token(GET).value)
				free(fetch_token(GET).value);
			reset_minishell(ast, std_fd);
		}
		free(command_line);
	}
	return (EXIT_SUCCESS);
}
