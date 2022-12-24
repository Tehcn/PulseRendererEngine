export class Vector3 {
    x: number;
    y: number;
    z: number;
    arr: number[];

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.arr = [x, y, z];
    }
}