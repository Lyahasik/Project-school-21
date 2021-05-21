/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:36:54 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/14 08:53:55 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_IN				"Usage: ./asm file_name.s\n"
# define ERR_NO_READ		"ERROR: file %s couldn't be read\n"
# define ERR_NO_READ_2		"ERROR: couldn't read line %d (%s)\n"
# define ERR_NO_NAME_COM	"ERROR: champ name or comment is not set\n"
# define ERR_NAME_COM		"ERROR: check name or comment in line %d\n"
# define ERR_NO_NAME		"ERROR: champ name is not set\n"
# define ERR_NO_COMMENT		"ERROR: Champ comment is not set\n"
# define ERR_NO_INSTR		"ERROR: Champ has no instructions\n"
# define ERR_NO_ARG			"ERROR: no arguments at line %d\n"
# define ERR_NAME_LENGTH	"ERROR: .name too long (%d) > max len (%d)\n"
# define ERR_COM_LENGTH		"ERROR: .coment too long (%d) > max len (%d)\n"
# define ERR_INST_LENGTH	"ERROR: inst. id %d for op. namber %d is invalid\n"
# define ERR_NO_N			"ERROR: no '\\n' at the end of the file\n"
# define ERR_ID				"ERROR: id for operation namber %d is invalid\n"
# define ERR_OP				"ERROR: op. %d enumeration sequence is wrong\n"
# define ERR_OP_POS			"ERROR: operation namber %d position is wrong\n"
# define ERR_OP_ARG			"ERROR: operation %d arg %d is reg %d - invalid"
# define ERR_MANY_ARG		"ERROR: too many arguments for instr nr %d"
# define ERR_ARG			"ERROR: invalid argument type\n"
# define ERR_ARG_LABEL		"ERROR: incompatible arg-label combination\n"
# define ERR_LABEL_1		"ERROR: label %d for operation %d not found\n"
# define ERR_LABEL_2		"ERROR: label %s not found\n"
# define ERR_ARG_NEG		"ERROR: negative argument type for operation %d\n"
# define ERR_REG			"ERROR: invalid registry value for operation %d\n"
# define ERR_SIZE_OP		"ERROR: wrong opsize, operation %d\n"
# define ERR_NOT_CR			"ERROR: file %s not created\n"
# define GOOD_OUT			"Writing output program to %s\n"
# define ERR_OUT_NAME		"ERROR: output file name not defined\n"
# define ERR_OUT_FILE		"ERROR: output file name couldn't be set\n"
# define ERR_MAX_VAL		"ERROR: MAX_ARG value is not valid\n"
# define ERR_ARG_NEVAL		"ERROR: an argument is not valid(line %d)\n"
# define ERR_ARG_NEVAL_2	"ERROR: argument '%s' is invalid (line %d)\n"
# define ERR_ARG_WRONG		"ERROR: wrong arguments amount(line %d)\n"
# define ERR_ARG_EXCESS		"ERROR: excess args (>MAX_ARG) at line %d\n"
# define ERR_LAST_LBL		"ERROR: last label points to nothing\n"
# define ERR_NO_OP			"ERROR: no operation\n"
#endif
