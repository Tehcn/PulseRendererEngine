import { Block } from "./blocks";
import { Vector3 } from "./vector3";

export class Chunk {
    centerPos: Vector3;
    blocks: Block[];

    constructor(centerPos: Vector3) {
        this.centerPos = centerPos;
    }

    addBlock(block: Block): this {
        this.blocks.push(block);
        return this;
    }

    removeBlock(block: Block): this {
        this.blocks = this.blocks.filter(b => b != block);
        return this;
    }

    addBlocks(blocks: Block[]): this {
        this.blocks.push(...blocks);
        return this;
    }

    removeBlocks(blocks: Block[]): this {
        blocks.forEach(block => this.removeBlock(block));
        return this;
    }
}
