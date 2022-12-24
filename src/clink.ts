import { spawn, ChildProcessWithoutNullStreams, SpawnOptionsWithoutStdio, execSync } from 'child_process'
import Logger from '@tehcn/log4js';

export class CProgram {
    sourceFiles: string[];
    executablePath?: string;
    logger: Logger;

    constructor() { this.sourceFiles = []; this.logger = new Logger('CProgram'); }

    addSourceFile(path: string): this {
        this.sourceFiles.push(path);
        this.logger.debug(`Added file ${path} to CProgram`);
        return this;
    }

    addSourceFiles(...paths: string[]): this {
        paths.forEach(path => this.addSourceFile(path));
        return this;
    }

    compile(to: string, flags?: string[]): this {
        if (flags) execSync(`g++ -o ${to} ${flags.join(' ')} ${this.sourceFiles.join(' ')}`, { cwd: 'D:/dev/Pulse/PulseRendererEngine' });
        else execSync(`g++ -o ${to} ${this.sourceFiles.join(' ')}`, { cwd: 'D:/dev/Pulse/PulseRendererEngine' });
        this.logger.debug(`Compiled to CProgram ${to}`);
        this.executablePath = to;
        return this;
    }

    run(...args: any[]): CLink {
        if (!this.executablePath)
            throw new Error('Program must be compiled first! (Use compile method)');
        else return new CLink(this.executablePath, args);
    }
}

class CLink {
    executablePath: string;
    proc: ChildProcessWithoutNullStreams;
    pid: number | undefined;
    logger: Logger;

    constructor(executablePath: string, args: any[]) {
        this.executablePath = executablePath;
        // if (this.executablePath.startsWith('./')) this.executablePath = this.executablePath.replace('./', '');
        this.proc = spawn(`${this.executablePath}`, [...args], { stdio: ['pipe'] });
        this.pid = this.proc.pid;
        this.logger = new Logger(`CLink ${this.pid}`);
    }

    public get stdout(): typeof this.proc.stdout {
        return this.proc.stdout;
    }

    public get stdin(): typeof this.proc.stdin {
        return this.proc.stdin;
    }

    public get stderr(): typeof this.proc.stderr {
        return this.proc.stderr;
    }

    public get addEventListener(): typeof this.proc.addListener {
        return this.proc.addListener;
    }

    // TODO: Make this work
    // addEventListener(event: string, listener: (...args: any[]) => void): this {
    //     this.proc.addListener(event, listener)
    //     return this;
    // }
}
