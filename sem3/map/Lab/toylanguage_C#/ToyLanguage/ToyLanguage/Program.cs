using System.Collections.Generic;
using ToyLanguage.Controller;
using ToyLanguage.Models.Expressions;
using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.Statements;
using ToyLanguage.Models.States;
using ToyLanguage.Repository;
using ToyLanguage.Views;

namespace ToyLanguage
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var program = new ProgramState()
            {
                ExecutionStack = GetExampleProgram2()
            };
            IRepository repository = new Repository.Repository(
                "/home/bogdanboboc97/RiderProjects/ToyLanguage/ToyLanguage/logFile.txt", 
                new List<ProgramState>( new[] { program }));
            var controller = new ToyLanguageController(repository);

            var menu = new TextMenu();
            
            menu.AddCommand(new ExitCommand(controller));
            menu.AddCommand(new RunProgramCommand(controller));

            menu.Run();
        }

        public static Stack<IStatement> GetExampleProgram1()
        {
            var exeStack = new Stack<IStatement>();
            
            IStatement firstStatement = new AssignmentStatement(
                "x",
                new ArithmeticExpression(
                    new ConstantExpression(1),
                    "-",
                    new ConstantExpression(8))
            );
            
            IStatement secondStatement = new IfStatement(
                new AssignmentStatement(
                    "x",
                    new ArithmeticExpression(
                        new VariableExpression("x"),
                        "+",
                        new ConstantExpression(2)
                        )
                    ),
                new VariableExpression("x"),
                new AssignmentStatement(
                    "x",
                    new ConstantExpression(-200)
                    )
            );
            
            IStatement thirdStatement = new PrintStatement(
                new VariableExpression("x")
            );
            
            exeStack.Push(thirdStatement);
            exeStack.Push(secondStatement);
            exeStack.Push(firstStatement);

            return exeStack;
        }
        
        public static Stack<IStatement> GetExampleProgram2()
        {
            var exeStack = new Stack<IStatement>();
            
            IStatement firstStatement = new OpenFileStatement(
                "fl",
                "/home/bogdanboboc97/RiderProjects/ToyLanguage/ToyLanguage/varFile.txt"
            );
            
            IStatement secondStatement = new ReadFromFileStatement(
                "x",
                new VariableExpression("fl")
            );
            
            IStatement thirdStatement = new IfStatement(
                new AssignmentStatement(
                    "x",
                    new ArithmeticExpression(
                        new VariableExpression("x"),
                        "+",
                        new ConstantExpression(2)
                    )
                ),
                new VariableExpression("x"),
                new AssignmentStatement(
                    "x",
                    new ConstantExpression(-200)
                )
            );
            
            IStatement fourthStatement = new PrintStatement(
                new VariableExpression("x")
            );
            
            IStatement fifthStatement = new CloseFileStatement(
                new VariableExpression("fl")
            );
            
            exeStack.Push(fifthStatement);
            exeStack.Push(fourthStatement);
            exeStack.Push(thirdStatement);
            exeStack.Push(secondStatement);
            exeStack.Push(firstStatement);

            return exeStack;
        }
    }
}
